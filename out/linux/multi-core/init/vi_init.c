#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/version.h>
#include <linux/of_platform.h>

#include "hi_comm_video.h"
#include "hi_common.h"
#include "hi_osal.h"
#include "vi.h"

extern int VI_ModInit(void);
extern void VI_ModExit(void);


#define                  VI_NAME_LEN           10

extern unsigned int viproc_en[VIPROC_IP_NUM];
module_param_array(viproc_en, uint, HI_NULL, S_IRUGO);

extern void*            g_pastViCapReg[VICAP_IP_NUM];
extern void*            g_pastViProcReg[VIPROC_IP_NUM];
extern unsigned int     g_astViCapIrqNum[VICAP_IP_NUM];
extern unsigned int     g_astViProcIrqNum[VIPROC_IRQ_NUM];

static int hi35xx_vi_probe(struct platform_device* pdev)
{
    HI_U32   i;
    HI_S32   s32Ret;
    HI_U8    u8ViCapName[VICAP_IP_NUM][VI_NAME_LEN];
    HI_U8    u8ViProcName[VIPROC_IP_NUM][VI_NAME_LEN];
    struct   resource*    mem;

    for (i = 0; i < VICAP_IP_NUM; i++)
    {
        snprintf(u8ViCapName[i], sizeof(u8ViCapName[i]), "VI_CAP%d", i);
        mem = osal_platform_get_resource_byname(pdev, IORESOURCE_MEM, u8ViCapName[i]);
        g_pastViCapReg[i] = devm_ioremap_resource(&pdev->dev, mem);

        if (IS_ERR(g_pastViCapReg[i]))
        {
            return PTR_ERR(g_pastViCapReg[i]);
        }

        g_astViCapIrqNum[i] = osal_platform_get_irq_byname(pdev, u8ViCapName[i]);

        if (g_astViCapIrqNum[i] <= 0)
        {
            dev_err(&pdev->dev, "can not find vi cap IRQ\n");
            return HI_FAILURE;
        }
    }

    for (i = 0; i < VIPROC_IP_NUM; i++)
    {
        snprintf(u8ViProcName[i], sizeof(u8ViProcName[i]), "VI_PROC%d", i);
        mem = osal_platform_get_resource_byname(pdev, IORESOURCE_MEM, u8ViProcName[i]);
        g_pastViProcReg[i] = devm_ioremap_resource(&pdev->dev, mem);

        if (IS_ERR(g_pastViProcReg[i]))
        {
            return PTR_ERR(g_pastViProcReg[i]);
        }

        g_astViProcIrqNum[i] = osal_platform_get_irq_byname(pdev, u8ViProcName[i]);

        if (g_astViProcIrqNum[i] <= 0)
        {
            dev_err(&pdev->dev, "can not find vi proc IRQ\n");
            return HI_FAILURE;
        }
    }

    s32Ret = VI_ModInit();
    if (HI_SUCCESS != s32Ret)
    {
        return HI_FAILURE;
    };

    return 0;
}

static int hi35xx_vi_remove(struct platform_device* pdev)
{
    HI_U32  i;
    VI_ModExit();

    for (i = 0; i < VICAP_IP_NUM; i++)
    {
        g_pastViCapReg[i] = HI_NULL;
    }

    for (i = 0; i < VIPROC_IP_NUM; i++)
    {
        g_pastViProcReg[i] = HI_NULL;
    }

    return 0;
}


static const struct of_device_id hi35xx_vi_match[] =
{
    { .compatible = "hisilicon,hisi-vi" },
    {},
};
MODULE_DEVICE_TABLE(of, hi35xx_vi_match);

static struct platform_driver hi35xx_vi_driver =
{
        .probe          = hi35xx_vi_probe,
        .remove         = hi35xx_vi_remove,
        .driver         = {
                .name   = "hi35xx_vi",
                .of_match_table = hi35xx_vi_match,
        },
};

osal_module_platform_driver(hi35xx_vi_driver);


MODULE_LICENSE("Proprietary");


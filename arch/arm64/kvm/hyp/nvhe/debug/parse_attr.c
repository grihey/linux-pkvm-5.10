#define STAGE1          1
#define STAGE2          2

#include <linux/kernel.h>
#include <nvhe/mem_protect.h>

#define S1_PXN_SHIFT            53
#define S1_PXN                  (1UL << S1_PXN_SHIFT)

#define S1_UXN_SHIFT            54
#define S1_UXN                  (1UL << S1_UXN_SHIFT)


/* Stage 2 */
#define S2_XN_SHIFT             53
#define S2_XN_MASK              (0x3UL << S2_XN_SHIFT)
#define S2_EXEC_EL1EL0          (0x0UL << S2_XN_SHIFT)
#define S2_EXEC_EL0             (0x1UL << S2_XN_SHIFT)
#define S2_EXEC_NONE            (0x2UL << S2_XN_SHIFT)
#define S2_EXEC_EL1             (0x3UL << S2_XN_SHIFT)

#define S2AP_SHIFT              6
#define S2AP_MASK               (0x3UL << S2AP_SHIFT)
#define S2AP_NONE               (0 << S2AP_SHIFT)
#define S2AP_READ               (1UL << S2AP_SHIFT)
#define S2AP_WRITE              (2UL << S2AP_SHIFT)
#define S2AP_RW                 (3UL << S2AP_SHIFT)

#define PAGE_HYP_RW             (S2_EXEC_NONE | S2AP_RW)     //0x400000000000c0
#define PAGE_HYP_RWX            (S2_EXEC_EL1EL0 | S2AP_RW)   //0x000000000000c0
#define PAGE_HYP_RO             (S2_EXEC_NONE | S2AP_READ)   //0x40000000000040
#define PAGE_HYP_EXEC           (S2_EXEC_EL1EL0 | S2AP_READ) //0x00000000000040

#define S2_MEM_ATTR_SHIFT       2
#define S2_MEM_ATTR_MASK        (0x0fUL << S2_MEM_ATTR_SHIFT)
#define S2_MEMTYPE_DEVICE       0

/* Shareability SH [9:8], Stage 1 and 2 */
#define SH_SHIFT                0x8
#define SH_NO                   0x0
#define SH_OUT                  0x2
#define SH_INN                  0x3

#define S2_SH_INN               (SH_INN << SH_SHIFT)

/* Stage 2 MemAttr[3:2] */
#define S2_MEM_ATTR_SHIFT       2
#define S2_MEM_TYPE_SHIFT       (S2_MEM_ATTR_SHIFT + 2)
#define S1_AP_SHIFT             6
#define S1_AP_MASK              (0x3UL << S1_AP_SHIFT)

#define S1_AP_RW_N              0UL
#define S1_AP_RW_RW             (1UL << S1_AP_SHIFT)
#define S1_AP_RO_N              (2UL << S1_AP_SHIFT)
#define S1_AP_RO_RO             (3UL << S1_AP_SHIFT)

#define PAGE_KERNEL_RW          S1_UXN              //0x40000000000000
#define PAGE_KERNEL_RWX         0x00000000000000
#define PAGE_KERNEL_RO          (S1_UXN | S1_AP_RO_N) //0x40000000000080
#define PAGE_KERNEL_EXEC        S1_AP_RO_N          //0x00000000000080

/* Stage 2 */
#define S2_XN_SHIFT             53
#define S2_XN_MASK              (0x3UL << S2_XN_SHIFT)
#define S2_EXEC_EL1EL0          (0x0UL << S2_XN_SHIFT)
#define S2_EXEC_EL0             (0x1UL << S2_XN_SHIFT)
#define S2_EXEC_NONE            (0x2UL << S2_XN_SHIFT)
#define S2_EXEC_EL1             (0x3UL << S2_XN_SHIFT)

#define S2AP_SHIFT              6
#define S2AP_MASK               (0x3UL << S2AP_SHIFT)
#define S2AP_NONE               (0 << S2AP_SHIFT)
#define S2AP_READ               (1UL << S2AP_SHIFT)
#define S2AP_WRITE              (2UL << S2AP_SHIFT)
#define S2AP_RW                 (3UL << S2AP_SHIFT)

#define PAGE_HYP_RW             (S2_EXEC_NONE | S2AP_RW)     //0x400000000000c0
#define PAGE_HYP_RWX            (S2_EXEC_EL1EL0 | S2AP_RW)   //0x000000000000c0
#define PAGE_HYP_RO             (S2_EXEC_NONE | S2AP_READ)   //0x40000000000040
#define PAGE_HYP_EXEC           (S2_EXEC_EL1EL0 | S2AP_READ) //0x00000000000040

#define S2_MEM_ATTR_SHIFT       2
#define S2_MEM_ATTR_MASK        (0x0fUL << S2_MEM_ATTR_SHIFT)
#define S2_MEMTYPE_DEVICE       0

/* Shareability SH [9:8], Stage 1 and 2 */
#define SH_SHIFT                0x8
#define SH_NO                   0x0
#define SH_OUT                  0x2
#define SH_INN                  0x3

#define S2_SH_INN               (SH_INN << SH_SHIFT)

/* Stage 2 MemAttr[3:2] */
#define S2_MEM_ATTR_SHIFT       2
/* Shareability SH [9:8], Stage 1 and 2 */
#define SH_SHIFT                0x8
#define SH_NO                   0x0
#define SH_OUT                  0x2S2_OWB
#define SH_INN                  0x3

#define S2_SH_INN               (SH_INN << SH_SHIFT)

/* Stage 2 MemAttr[3:2] */
#define S2_MEM_ATTR_SHIFT       2
#define S2_MEM_TYPE_SHIFT       (S2_MEM_ATTR_SHIFT + 2)
#define S2_MEM_TYPE_MASK        (0x3 << S2_MEM_TYPE_SHIFT)
#define S2_DEVICE               (0x0 << S2_MEM_TYPE_SHIFT)
#define S2_ONONE                (0x1 << S2_MEM_TYPE_SHIFT)
#define S2_OWT                  (0x2 << S2_MEM_TYPE_SHIFT)
#define S2_OWB                  (0x3 << S2_MEM_TYPE_SHIFT)

/* Stage 2 MemAttr[1:0] Meaning when MemAttr[3:2] == 0b00 */
#define NGNRNE                  (0x0 << S2_MEM_ATTR_SHIFT)
#define NGNRE                   (0x1 << S2_MEM_ATTR_SHIFT)
#define NGRE                    (0x2 << S2_MEM_ATTR_SHIFT)
#define GRE                     (0x3 << S2_MEM_ATTR_SHIFT)

/* Stage 2 MemAttr[1:0] Meaning when MemAttr[3:2] != 0b00 */
/* Inner Non-cacheable */
#define S2_INONE                (0x1 << S2_MEM_ATTR_SHIFT)
/* Inner Write-Through Cacheable */
#define S2_IWT                  (0x2 << S2_MEM_ATTR_SHIFT)
/* Inner Write-Back Cacheable */
#define S2_IWB                  (0x3 << S2_MEM_ATTR_SHIFT)

/* Stage 2 device memory attributes */
#define S2_DEV_NGNRNE           (S2_DEVICE | NGNRNE)
#define S2_DEV_NGNRE            (S2_DEVICE | NGNRE)
#define S2_DEV_NGRE             (S2_DEVICE | NGRE)
#define S2_DEV_GRE              (S2_DEVICE | GRE)



int hyp_snprint(char *s, size_t slen, const char *fmt, ...);

#if 1
char *parse_attrs(char *p, uint64_t attrs, uint64_t stage)
{
        const char *pv_access = "R-";
        const char *upv_access = "--";
        const char *state = "";
        char pv_perm = '-';
        char upv_perm = '-';
        const char *mtype = "";

        if (p == 0) {
                if (stage == STAGE2)
                        return "prv usr type";
                else
                        return "prv usr";
        }

        //if ((stage == STAGE1) || (stage == EL2_STAGE1)) {
         if (stage == STAGE1) {
                pv_perm = (attrs & S1_PXN) ? '-' : 'X';
                upv_perm = (attrs & S1_UXN) ? '-' : 'X';

                switch (attrs & S1_AP_MASK) {
                case S1_AP_RW_N:
                        pv_access = "RW";
                        upv_access = "--";
                        break;
                case S1_AP_RW_RW:
                        pv_access = "RW";
                        upv_access = "RW";
                        if (pv_perm == 'X') {
                                /* Not executable, because AArch64 execution
                                 * treats all regions writable at EL0 as being PXN
                                 */
                                pv_perm = 'x';
                        }
                        break;
                case S1_AP_RO_N:
                        pv_access = "R-";
                        upv_access = "--";
                        break;
                case S1_AP_RO_RO:
                        pv_access = "R-";
                        upv_access = "R-";
                        break;
                }
        } else if (stage == STAGE2) {
                switch (attrs & S2_XN_MASK) {
                case S2_EXEC_EL1EL0:
                        pv_perm =  'X';
                        upv_perm = 'X';
                        break;
                case S2_EXEC_EL0:
                        pv_perm = '-';
                        upv_perm = 'X';
                        break;
                case S2_EXEC_NONE:
                        pv_perm = '-';
                        upv_perm = '-';
                        break;
                case S2_EXEC_EL1:
                        pv_perm = 'X';
                        upv_perm = '-';
                }

                switch (attrs & S2AP_MASK) {
                case S2AP_NONE:
                        pv_access = "--";
                        upv_access = "--";
                        break;
                case S2AP_READ:
                        pv_access = "R-";
                        upv_access = "R-";
                        break;
                case S2AP_WRITE:
                        pv_access = "-W";
                        upv_access = "-W";
                        break;
                case S2AP_RW:
                        pv_access = "RW";
                        upv_access = "RW";
                        break;
                }

                switch (attrs & PKVM_PAGE_STATE_PROT_MASK) {
                case PKVM_PAGE_SHARED_OWNED:
                	state = "SHARED_OWNED";
                	break;
                case PKVM_PAGE_SHARED_BORROWED:
                	state = "SHARED_BORROWED";
                	break;
                }
                mtype = ((attrs & S2_MEM_TYPE_MASK) == S2_DEVICE) ? "Device" :
                                       "Normal";
              //  kvm_pgtable_stage2_pte_prot()
        } else
                return "Unknown stage?";
        // hyp_printf("%s%c %s%c %s", pv_access, pv_perm, upv_access, upv_perm,
                 //        mtype);
        hyp_snprint(p,128, "%s%c %s%c %s %s", pv_access, pv_perm, upv_access, upv_perm,
                mtype,state);
        return p;
}
#endif

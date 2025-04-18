#ifdef __cplusplus
extern "C" {
#endif
#include "lmp_f2c.h"
static integer c__1 = 1;
static doublereal c_b14 = 1.;
static doublereal c_b25 = -1.;
int dlarfb_(char *side, char *trans, char *direct, char *storev, integer *m, integer *n, integer *k,
            doublereal *v, integer *ldv, doublereal *t, integer *ldt, doublereal *c__, integer *ldc,
            doublereal *work, integer *ldwork, ftnlen side_len, ftnlen trans_len, ftnlen direct_len,
            ftnlen storev_len)
{
    integer c_dim1, c_offset, t_dim1, t_offset, v_dim1, v_offset, work_dim1, work_offset, i__1,
        i__2;
    integer i__, j;
    extern int dgemm_(char *, char *, integer *, integer *, integer *, doublereal *, doublereal *,
                      integer *, doublereal *, integer *, doublereal *, doublereal *, integer *,
                      ftnlen, ftnlen);
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern int dcopy_(integer *, doublereal *, integer *, doublereal *, integer *),
        dtrmm_(char *, char *, char *, char *, integer *, integer *, doublereal *, doublereal *,
               integer *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, ftnlen);
    char transt[1];
    v_dim1 = *ldv;
    v_offset = 1 + v_dim1;
    v -= v_offset;
    t_dim1 = *ldt;
    t_offset = 1 + t_dim1;
    t -= t_offset;
    c_dim1 = *ldc;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    work_dim1 = *ldwork;
    work_offset = 1 + work_dim1;
    work -= work_offset;
    if (*m <= 0 || *n <= 0) {
        return 0;
    }
    if (lsame_(trans, (char *)"N", (ftnlen)1, (ftnlen)1)) {
        *(unsigned char *)transt = 'T';
    } else {
        *(unsigned char *)transt = 'N';
    }
    if (lsame_(storev, (char *)"C", (ftnlen)1, (ftnlen)1)) {
        if (lsame_(direct, (char *)"F", (ftnlen)1, (ftnlen)1)) {
            if (lsame_(side, (char *)"L", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(n, &c__[j + c_dim1], ldc, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"N", (char *)"U", n, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"N", n, k, &i__1, &c_b14, &c__[*k + 1 + c_dim1], ldc,
                           &v[*k + 1 + v_dim1], ldv, &c_b14, &work[work_offset], ldwork, (ftnlen)1,
                           (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", transt, (char *)"N", n, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"N", (char *)"T", &i__1, n, k, &c_b25, &v[*k + 1 + v_dim1], ldv,
                           &work[work_offset], ldwork, &c_b14, &c__[*k + 1 + c_dim1], ldc,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"T", (char *)"U", n, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *n;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[j + i__ * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            } else if (lsame_(side, (char *)"R", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(m, &c__[j * c_dim1 + 1], &c__1, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"N", (char *)"U", m, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"N", m, k, &i__1, &c_b14, &c__[(*k + 1) * c_dim1 + 1], ldc,
                           &v[*k + 1 + v_dim1], ldv, &c_b14, &work[work_offset], ldwork, (ftnlen)1,
                           (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", trans, (char *)"N", m, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"T", m, &i__1, k, &c_b25, &work[work_offset], ldwork,
                           &v[*k + 1 + v_dim1], ldv, &c_b14, &c__[(*k + 1) * c_dim1 + 1], ldc,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"T", (char *)"U", m, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *m;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[i__ + j * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            }
        } else {
            if (lsame_(side, (char *)"L", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(n, &c__[*m - *k + j + c_dim1], ldc, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"N", (char *)"U", n, k, &c_b14, &v[*m - *k + 1 + v_dim1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"N", n, k, &i__1, &c_b14, &c__[c_offset], ldc, &v[v_offset], ldv,
                           &c_b14, &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", transt, (char *)"N", n, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"N", (char *)"T", &i__1, n, k, &c_b25, &v[v_offset], ldv, &work[work_offset],
                           ldwork, &c_b14, &c__[c_offset], ldc, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"T", (char *)"U", n, k, &c_b14, &v[*m - *k + 1 + v_dim1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *n;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[*m - *k + j + i__ * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            } else if (lsame_(side, (char *)"R", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(m, &c__[(*n - *k + j) * c_dim1 + 1], &c__1, &work[j * work_dim1 + 1],
                           &c__1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"N", (char *)"U", m, k, &c_b14, &v[*n - *k + 1 + v_dim1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"N", m, k, &i__1, &c_b14, &c__[c_offset], ldc, &v[v_offset], ldv,
                           &c_b14, &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", trans, (char *)"N", m, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"T", m, &i__1, k, &c_b25, &work[work_offset], ldwork, &v[v_offset],
                           ldv, &c_b14, &c__[c_offset], ldc, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"T", (char *)"U", m, k, &c_b14, &v[*n - *k + 1 + v_dim1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *m;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[i__ + (*n - *k + j) * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            }
        }
    } else if (lsame_(storev, (char *)"R", (ftnlen)1, (ftnlen)1)) {
        if (lsame_(direct, (char *)"F", (ftnlen)1, (ftnlen)1)) {
            if (lsame_(side, (char *)"L", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(n, &c__[j + c_dim1], ldc, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"T", (char *)"U", n, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"T", n, k, &i__1, &c_b14, &c__[*k + 1 + c_dim1], ldc,
                           &v[(*k + 1) * v_dim1 + 1], ldv, &c_b14, &work[work_offset], ldwork,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", transt, (char *)"N", n, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"T", &i__1, n, k, &c_b25, &v[(*k + 1) * v_dim1 + 1], ldv,
                           &work[work_offset], ldwork, &c_b14, &c__[*k + 1 + c_dim1], ldc,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"N", (char *)"U", n, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *n;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[j + i__ * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            } else if (lsame_(side, (char *)"R", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(m, &c__[j * c_dim1 + 1], &c__1, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"T", (char *)"U", m, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"T", m, k, &i__1, &c_b14, &c__[(*k + 1) * c_dim1 + 1], ldc,
                           &v[(*k + 1) * v_dim1 + 1], ldv, &c_b14, &work[work_offset], ldwork,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", trans, (char *)"N", m, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"N", m, &i__1, k, &c_b25, &work[work_offset], ldwork,
                           &v[(*k + 1) * v_dim1 + 1], ldv, &c_b14, &c__[(*k + 1) * c_dim1 + 1], ldc,
                           (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"U", (char *)"N", (char *)"U", m, k, &c_b14, &v[v_offset], ldv, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *m;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[i__ + j * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            }
        } else {
            if (lsame_(side, (char *)"L", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(n, &c__[*m - *k + j + c_dim1], ldc, &work[j * work_dim1 + 1], &c__1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"T", (char *)"U", n, k, &c_b14, &v[(*m - *k + 1) * v_dim1 + 1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"T", n, k, &i__1, &c_b14, &c__[c_offset], ldc, &v[v_offset], ldv,
                           &c_b14, &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", transt, (char *)"N", n, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*m > *k) {
                    i__1 = *m - *k;
                    dgemm_((char *)"T", (char *)"T", &i__1, n, k, &c_b25, &v[v_offset], ldv, &work[work_offset],
                           ldwork, &c_b14, &c__[c_offset], ldc, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"N", (char *)"U", n, k, &c_b14, &v[(*m - *k + 1) * v_dim1 + 1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *n;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[*m - *k + j + i__ * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            } else if (lsame_(side, (char *)"R", (ftnlen)1, (ftnlen)1)) {
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    dcopy_(m, &c__[(*n - *k + j) * c_dim1 + 1], &c__1, &work[j * work_dim1 + 1],
                           &c__1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"T", (char *)"U", m, k, &c_b14, &v[(*n - *k + 1) * v_dim1 + 1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"T", m, k, &i__1, &c_b14, &c__[c_offset], ldc, &v[v_offset], ldv,
                           &c_b14, &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", trans, (char *)"N", m, k, &c_b14, &t[t_offset], ldt, &work[work_offset],
                       ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                if (*n > *k) {
                    i__1 = *n - *k;
                    dgemm_((char *)"N", (char *)"N", m, &i__1, k, &c_b25, &work[work_offset], ldwork, &v[v_offset],
                           ldv, &c_b14, &c__[c_offset], ldc, (ftnlen)1, (ftnlen)1);
                }
                dtrmm_((char *)"R", (char *)"L", (char *)"N", (char *)"U", m, k, &c_b14, &v[(*n - *k + 1) * v_dim1 + 1], ldv,
                       &work[work_offset], ldwork, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
                i__1 = *k;
                for (j = 1; j <= i__1; ++j) {
                    i__2 = *m;
                    for (i__ = 1; i__ <= i__2; ++i__) {
                        c__[i__ + (*n - *k + j) * c_dim1] -= work[i__ + j * work_dim1];
                    }
                }
            }
        }
    }
    return 0;
}
#ifdef __cplusplus
}
#endif

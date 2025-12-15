#ifdef MATLAB
#ifdef GNU

#include "fintrf.h"

MODULE matlabproblem
   USE iso_c_binding
   USE scattersearchtypes

  CONTAINS

  SUBROUTINE openmatlab(ep,option) 
    IMPLICIT NONE
    integer*8, INTENT(INOUT) :: ep
    integer(C_INT), INTENT(INOUT) :: option
    integer*8 :: engOpen, num
    integer*8 :: complexity = 0
    integer*8 :: E
    integer*8 :: E_ptr
    REAL*8, DIMENSION(1,1) :: vars
    integer*8 :: status, mxCreateDoubleMatrix, mxGetPr
    integer*8 :: engPutVariable, engEvalString

    ep = engOpen('matlab -R -nodisplay -nojvm -nosplash')
    if (ep .eq. 0) then
         write(6,*) 'Can''t start MATLAB engine'
         STOP
    endif
   
    num = 1
    E = mxCreateDoubleMatrix(num, num, complexity)
    E_ptr = mxGetPr(E)

    vars = REAL(0d0,8)
    CALL mxCopyReal8ToPtr(vars, E_ptr, num)

    status = engPutVariable(ep, 'E', E)
    IF (status .ne. 0) THEN
        WRITE(6,*) 'engPutVariable failed'
        STOP
    ENDIF
 
    IF (option .EQ. 1) then
       status = engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
       IF (engEvalString(ep, '[e]=initParametersNLP(E);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
       ENDIF
    ELSE IF (option .EQ. 2) then
       status = engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
       IF (engEvalString(ep, '[e]=initParametersMINLP(E);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
       ENDIF
    ELSE
       status = engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
       IF (engEvalString(ep, '[e]=initParametersPE(E);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
       ENDIF
    END IF

        

  END SUBROUTINE

  SUBROUTINE closematlab(ep)
   IMPLICIT NONE
   integer*8 :: engClose
   integer*8 :: status
   integer*8, INTENT(INOUT) :: ep

   status=engClose(ep)
   IF (status .ne. 0) THEN
          WRITE(*,*) 'Failed to close MATLAB engine'
          STOP
   ELSE
          WRITE(*,*) 'Closed MATLAB engine'
   ENDIF
  
   RETURN

  END SUBROUTINE

  SUBROUTINE matlabobjfunc(x,m,res,omt,ep,option)
  IMPLICIT NONE                   
  INTEGER, INTENT(IN) :: option
  TYPE(C_PTR) ,INTENT(INOUT) ::  omt
  REAL(KIND=SELECTED_REAL_KIND(P=PRECISION_D,R=RANGE_D)),  INTENT(INOUT) :: res 
  INTEGER, INTENT(INOUT)  :: m
  integer*8, INTENT(INOUT) :: ep
  INTEGER*8 :: n, m1, size_r, size_g, size_j
  REAL(KIND=SELECTED_REAL_KIND(P=PRECISION_D,R=RANGE_D)), INTENT(INOUT)  :: x(m)
  REAL*8, DIMENSION(:) , ALLOCATABLE  :: res2
  REAL*8, DIMENSION(1,m) :: vars
  integer*8  :: mxCreateDoubleMatrix, mxGetN
  integer*8 :: mxGetPr
  integer*8 :: complexity = 0
  integer*8 :: engGetVariable, status
  integer*8 :: engPutVariable, engEvalString
  integer*8 :: temp
  integer*8 :: V 
  integer*8 :: V_ptr
 
  integer*8 :: F, F_ptr
  integer*8 :: R, R_ptr
  integer*8 :: G, G_ptr
  real*8, DIMENSION(:), ALLOCATABLE :: resi, gfort
  real*8 :: dimm(2)
  integer*8 :: dimm_ptr

  n=1
  m1=m
  ALLOCATE(res2(1))
  vars(1,:)=REAL(x,8)

  V = mxCreateDoubleMatrix(n, m1, complexity)
  V_ptr = mxGetPr(V)

  CALL mxCopyReal8ToPtr(vars, V_ptr, m1)
  status = engPutVariable(ep, 'X', V)
  IF (status .ne. 0) THEN
      WRITE(6,*) 'engPutVariable failed'
      STOP
  ENDIF

  IF (option .EQ. 1) then
     status =engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
     IF (engEvalString(ep, '[F g] = matlabNLP(X);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
     ENDIF
  ELSE IF (option .EQ. 2) then
     status =engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
     IF (engEvalString(ep, '[F g] = matlabMINLP(X);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
     ENDIF
  ELSE
     status = engEvalString(ep,"addpath(genpath('../bitbucket/benchmarks/matlab'))");
     IF (engEvalString(ep, '[F R] = matlabPE(X);') .ne. 0) THEN
          write(6,*) 'engEvalString failed'
          STOP
     ENDIF
  END IF


  F = engGetVariable(ep, 'F')
  F_ptr = mxGetPr(F)
  CALL mxCopyPtrToReal8(F_ptr, res2, n)

  size_r = 0
  if ( option .eq. 0) then 
     R = engGetVariable(ep, 'R')
     R_ptr = mxGetPr(R)
     m1=mxGetN(R)
     size_r = m1
     if (m1 .GT. 0 ) then
       ALLOCATE(resi(m1))
       CALL mxCopyPtrToReal8(R_ptr,resi,m1)
       CALL setoutputmatlabres(omt, resi,  size_r);
     end if
  end if

  size_g = 0
  if (( option .EQ. 2 ) .or. ( option .EQ. 1 ) ) then
     G = engGetVariable(ep, 'g')
     G_ptr = mxGetPr(G)
     m1=mxGetN(G)
     size_g = m1
     if (m1 .GT. 0 ) then
         ALLOCATE(gfort(m1))
         CALL mxCopyPtrToReal8(G_ptr,gfort,m1)
         CALL setoutputmatlabpen(omt, gfort, size_g);
     end if
  end if


   if (size_r .GT. 0 ) DEALLOCATE(resi)
   if (size_g .GT. 0 ) DEALLOCATE(gfort)

   res=res2(1)

   DEALLOCATE(res2)
   CALL mxDestroyArray(V)
   if ( option .eq. 0) CALL mxDestroyArray(R)
   if (( option .EQ. 2 ) .or. ( option .EQ. 1 ) ) then 
     CALL mxDestroyArray(G)      
     CALL mxDestroyArray(F)
   end if

   RETURN


   END SUBROUTINE matlabobjfunc

END MODULE matlabproblem

#endif
#endif


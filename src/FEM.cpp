#include "cpp_headers.h"

/*
node id per cell
N3...N4
.     .
.     .
N1...N2

N1 = (1-xi)*(1-eta)
N2 = xi*(1-eta)
N3 = (1-xi)*eta
N4 = xi*eta

integrals over D=[0,1]*[0,1]:

int_D Ni*Nj dxi deta = [1/9, 1/18, 1/18, 1/36
                        1/18, 1/9, 1/36, 1/18
                        1/18, 1/36, 1/9, 1/18
                        1/36, 1/18, 1/18, 1/9]
*/
double dNxi(int i, double xi, double eta){
  if(i==0){
    return eta-1.0;
  }
  else if(i==1){
    return 1.0-eta;
  }
  else if(i==2){
    return -eta;
  }
  else{
    return eta;
  }
}
double dNeta(int i, double xi, double eta){
  if(i==0){
    return xi-1.0;
  }
  else if(i==1){
    return -xi;
  }
  else if(i==2){
    return -xi+1;
  }
  else{
    return xi;
  }
}
//void compute_intdudvdx(double **dudv, double j11, double j12, double j21, double j22, double detJinv){
void compute_intdudvdx(double **dudv){
  // This part of code is generated by python.
  // Integrals are computed analytically
  // the 4*4 array dudv is allocated before this function call
  /*
     dudv[0][0] = (1.0/3.0)*pow(j11, 2) + (1.0/2.0)*j11*j12 + (1.0/3.0)*pow(j12, 2) + (1.0/3.0)*pow(j21, 2) + (1.0/2.0)*j21*j22 + (1.0/3.0)*pow(j22, 2);
     dudv[0][1] = -1.0/3.0*pow(j11, 2) + (1.0/6.0)*pow(j12, 2) - 1.0/3.0*pow(j21, 2) + (1.0/6.0)*pow(j22, 2);
     dudv[0][2] = (1.0/6.0)*pow(j11, 2) - 1.0/3.0*pow(j12, 2) + (1.0/6.0)*pow(j21, 2) - 1.0/3.0*pow(j22, 2);
     dudv[0][3] = -1.0/6.0*pow(j11, 2) - 1.0/2.0*j11*j12 - 1.0/6.0*pow(j12, 2) - 1.0/6.0*pow(j21, 2) - 1.0/2.0*j21*j22 - 1.0/6.0*pow(j22, 2);
     dudv[1][0] = -1.0/3.0*pow(j11, 2) + (1.0/6.0)*pow(j12, 2) - 1.0/3.0*pow(j21, 2) + (1.0/6.0)*pow(j22, 2);
     dudv[1][1] = (1.0/3.0)*pow(j11, 2) - 1.0/2.0*j11*j12 + (1.0/3.0)*pow(j12, 2) + (1.0/3.0)*pow(j21, 2) - 1.0/2.0*j21*j22 + (1.0/3.0)*pow(j22, 2);
     dudv[1][2] = -1.0/6.0*pow(j11, 2) + (1.0/2.0)*j11*j12 - 1.0/6.0*pow(j12, 2) - 1.0/6.0*pow(j21, 2) + (1.0/2.0)*j21*j22 - 1.0/6.0*pow(j22, 2);
     dudv[1][3] = (1.0/6.0)*pow(j11, 2) - 1.0/3.0*pow(j12, 2) + (1.0/6.0)*pow(j21, 2) - 1.0/3.0*pow(j22, 2);
     dudv[2][0] = (1.0/6.0)*pow(j11, 2) - 1.0/3.0*pow(j12, 2) + (1.0/6.0)*pow(j21, 2) - 1.0/3.0*pow(j22, 2);
     dudv[2][1] = -1.0/6.0*pow(j11, 2) + (1.0/2.0)*j11*j12 - 1.0/6.0*pow(j12, 2) - 1.0/6.0*pow(j21, 2) + (1.0/2.0)*j21*j22 - 1.0/6.0*pow(j22, 2);
     dudv[2][2] = (1.0/3.0)*pow(j11, 2) - 1.0/2.0*j11*j12 + (1.0/3.0)*pow(j12, 2) + (1.0/3.0)*pow(j21, 2) - 1.0/2.0*j21*j22 + (1.0/3.0)*pow(j22, 2);
     dudv[2][3] = -1.0/3.0*pow(j11, 2) + (1.0/6.0)*pow(j12, 2) - 1.0/3.0*pow(j21, 2) + (1.0/6.0)*pow(j22, 2);
     dudv[3][0] = -1.0/6.0*pow(j11, 2) - 1.0/2.0*j11*j12 - 1.0/6.0*pow(j12, 2) - 1.0/6.0*pow(j21, 2) - 1.0/2.0*j21*j22 - 1.0/6.0*pow(j22, 2);
     dudv[3][1] = (1.0/6.0)*pow(j11, 2) - 1.0/3.0*pow(j12, 2) + (1.0/6.0)*pow(j21, 2) - 1.0/3.0*pow(j22, 2);
     dudv[3][2] = -1.0/3.0*pow(j11, 2) + (1.0/6.0)*pow(j12, 2) - 1.0/3.0*pow(j21, 2) + (1.0/6.0)*pow(j22, 2);
     dudv[3][3] = (1.0/3.0)*pow(j11, 2) + (1.0/2.0)*j11*j12 + (1.0/3.0)*pow(j12, 2) + (1.0/3.0)*pow(j21, 2) + (1.0/2.0)*j21*j22 + (1.0/3.0)*pow(j22, 2);
    */
    dudv[0][0] = 2.0/3.0;
     dudv[0][1] = -1.0/6.0;
     dudv[0][2] = -1.0/6.0;
     dudv[0][3] = -1.0/3.0;
     dudv[1][0] = -1.0/6.0;
     dudv[1][1] = 2.0/3.0;
     dudv[1][2] = -1.0/3.0;
     dudv[1][3] = -1.0/6.0;
     dudv[2][0] = -1.0/6.0;
     dudv[2][1] = -1.0/3.0;
     dudv[2][2] = 2.0/3.0;
     dudv[2][3] = -1.0/6.0;
     dudv[3][0] = -1.0/3.0;
     dudv[3][1] = -1.0/6.0;
     dudv[3][2] = -1.0/6.0;
     dudv[3][3] = 2.0/3.0;
}
void compute_intuvdx(double **uv){
  // This part of code is generated by python.
  // Integrals are computed analytically
  // the 4*4 array uv is allocated before this function call
       uv[0][0] = 1.0/9.0;
       uv[0][1] = 1.0/18.0;
       uv[0][2] = 1.0/18.0;
       uv[0][3] = 1.0/36.0;
       uv[1][0] = 1.0/18.0;
       uv[1][1] = 1.0/9.0;
       uv[1][2] = 1.0/36.0;
       uv[1][3] = 1.0/18.0;
       uv[2][0] = 1.0/18.0;
       uv[2][1] = 1.0/36.0;
       uv[2][2] = 1.0/9.0;
       uv[2][3] = 1.0/18.0;
       uv[3][0] = 1.0/36.0;
       uv[3][1] = 1.0/18.0;
       uv[3][2] = 1.0/18.0;
       uv[3][3] = 1.0/9.0;
}
void compute_intnvdx(double *v, double *n,double **uv){
  int i,j;
  for(i=0; i<4; i++){
    v[i] = 0.0;
    for(j=0; j<4; j++){
      v[i] += n[j]*uv[i][j];//*detJinv;
    }
  }
}
int compute_num_nonzeros(double **A, int n, double tol){
  int i,j, nnz;
  nnz = 0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(fabs(A[i][j])>tol){
        nnz++;
      }
    }
  }
  return nnz;
}
void transform_A_compact(double **A, int n, int *ia, int *ja, double *a, int nnz, double tol){
  // size of ia is  n+1
  // size of ja is nnz
  // size of a is nnz
  int i,j, id_nnz;
  id_nnz = 0;
  ia[0] = 0;
  for(i=0; i<n; i++){
    ia[i] = id_nnz;
    for(j=0; j<n; j++){
      if(fabs(A[i][j])>tol){
        a[id_nnz] = A[i][j];
        ja[id_nnz] = j;
        id_nnz++;
      }
    }
  }
  ia[n] = id_nnz;

  for(i=0; i<nnz; i++){
    ja[i]++;
  }
  for(i=0; i<n+1; i++){
    ia[i]++;
  }
}
double vlasov_taking_the_integral_2D(struct GAS *gas, struct BOX *box, struct CELLS *cells, double xx, double yy, double *rr, double *delt_r, double *phi, double *dphi, double *theta, double *dtheta, int NNr, int NNphi, int NNtheta){

  double pi = acos(-1);
  int i, ii, iii, num, j, k;
  double V, n;
  double x ,y, radial_part;
  V = 0.0;
  int out;
   for(i=0; i<NNr; i++){
     radial_part = pow((*gas).sigma/rr[i],6.0)*rr[i]*rr[i]*delt_r[i];
     for(ii=0; ii<NNphi; ii++){
       for(iii=0; iii<NNtheta; iii++){
         out = 0;
         x = xx + rr[i]*cos(phi[ii])*sin(theta[iii]);
         y = yy + rr[i]*sin(phi[ii])*sin(theta[iii]);
         j = floor(x/(*box).delta_dim[0]);
         k = floor(y/(*box).delta_dim[1]);
         if(j<0){
           j=0;
           out = 1;
         }
         else if(j>(*box).N[0]-1){
          j = (*box).N[0]-1;
          out = 1;
        }
         if(k<0){
           k=0;
           out = 1;
         }
         else if(k>(*box).N[1]-1){
          k = (*box).N[1]-1;
          out = 1;
        }
         num =  k*(*box).N[0] + j;
         n = cells[num].n;
         //if(out==1){
         //   n=0.0;
         //}
         V += radial_part*n*dphi[ii]*sin(theta[iii])*dtheta[iii];
       }
     }
   }

  return V;
}
double Compute_SP_using_Green_Function(struct GAS *gas, struct BOX *box, struct CELLS *cells, double xx, double yy, double *rr, double *delt_r, double *phi, double *dphi, double *theta, double *dtheta, int NNr, int NNphi, int NNtheta){

  double pi = acos(-1);
  int i, ii, iii, num, j, k;
  double V, n;
  double x ,y, radial_part;
  V = 0.0;

   int out;
   for(i=0; i<NNr; i++){
     radial_part = exp(-(*gas).bst*rr[i])/(4.0*pi)*rr[i]*delt_r[i];
     for(ii=0; ii<NNphi; ii++){
       for(iii=0; iii<NNtheta; iii++){
         out = 0;
         x = xx + rr[i]*cos(phi[ii])*sin(theta[iii]);
         y = yy + rr[i]*sin(phi[ii])*sin(theta[iii]);
         j = floor(x/(*box).delta_dim[0]);
         k = floor(y/(*box).delta_dim[1]);
         if(j<0){
           j=0;
           out = 1;
         }
         else if(j>(*box).N[0]-1){
          j = (*box).N[0]-1;
          out = 1;
        }
         if(k<0){
           k=0;
           out = 1;
         }
         else if(k>(*box).N[1]-1){
          k = (*box).N[1]-1;
          out = 1;
        }
         num =  k*(*box).N[0] + j;
         n = cells[num].n;
         //if(out==1){
         //   n=0.0;
         //}
         V += radial_part*n*dphi[ii]*sin(theta[iii])*dtheta[iii];
       }

     }
   }
  return V;
}
void compute_SP_2D(struct GAS *gas, struct BOX *box, struct CELLS *cells, double *x1, double *x2, double *U1, double *U2, int *index){
  int nn = ((*box).N[0]+1)*((*box).N[1]+1);
  int nc = (*box).N[0]*(*box).N[1];
  int nb = 4;
  int i,j,id, ii, jj, num, k;
  double **A = new double*[nn];
  double **dudv = new double*[nb];
  double **uv = new double*[nb];
  double *v = new double[nb];
  double *x = new double[nn];
  double *xe = new double[nn]; // for testing purposes
  double *b = new double[nn];
  //double Jinv[4], detJinv,
  double  n[4];
  double lambda2, pi;
  int ids[2], iids[2];
  pi = acos(-1.0);
  lambda2 = pow( (*gas).bst, 2.0);
  for(i = 0; i < nn; ++i)
    A[i] = new double[nn];
  for(i=0; i<nn; i++)
    for(j=0; j<nn; j++)
      A[i][j] = 0.0;
  for(i=0; i<nn; i++){
    b[i] = 0.0; x[i] = 0.0;
  }
  for(i = 0; i < nb; ++i){
    dudv[i] = new double[nb];
    uv[i] = new double[nb];
  }
   //FEM:
   compute_intdudvdx(dudv);
   compute_intuvdx(uv);

  for(num=0; num<nc; num++){

    //n[0] = sin(2.0*pi*(cells[num].cell_center[0]-0.5*cells[num].dx)/(*box).Len[0])*sin(2.0*pi*(cells[num].cell_center[1]-0.5*cells[num].dy)/(*box).Len[1]);
    //n[1] = sin(2.0*pi*(cells[num].cell_center[0]+0.5*cells[num].dx)/(*box).Len[0])*sin(2.0*pi*(cells[num].cell_center[1]-0.5*cells[num].dy)/(*box).Len[1]);
    //n[2] = sin(2.0*pi*(cells[num].cell_center[0]-0.5*cells[num].dx)/(*box).Len[0])*sin(2.0*pi*(cells[num].cell_center[1]+0.5*cells[num].dy)/(*box).Len[1]);
    //n[3] = sin(2.0*pi*(cells[num].cell_center[0]+0.5*cells[num].dx)/(*box).Len[0])*sin(2.0*pi*(cells[num].cell_center[1]+0.5*cells[num].dy)/(*box).Len[1]);

    //for(i=0; i<nb; i++){
    //  n[i] = -n[i]*2*lambda2;
    //}
    for(i=0; i<nb; i++){
      n[i] = cells[num].n_n[i];
    }

    compute_intnvdx(v, n, uv);
    for(i=0; i<nb; i++){
      for(j=0; j<nb; j++){
        A[cells[num].id[i]][cells[num].id[j]] += dudv[i][j];
        A[cells[num].id[i]][cells[num].id[j]] += lambda2*uv[i][j]*cells[num].volume;
      }
      b[cells[num].id[i]] += v[i]*cells[num].volume;
    }
  }

  // scale equations:

  //for(i=0; i<nn; i++){
  //  for(j=0; j<nn; j++){
  //    A[i][j]  = A[i][j]*(*gas).m;
  //  }
  //  b[i] = b[i] * (*gas).m;
  //}

/*
  for(j=0; j<(*box).N[1]+1; j++){
    for(i=0; i<(*box).N[0]+1; i++){
      id = j*((*box).N[0]+1)+i;
      if(i!=0){
        A[id][id-1] = -1.0;
      }
      if(i!=(*box).N[0]){
        A[id][id+1] = -1.0;
      }
      if(j!=0){
        A[id][id-((*box).N[0]+1)] = -1.0;
      }
      if(j!=(*box).N[0]){
        A[id][id+((*box).N[0]+1)] = -1.0;
      }
      A[id][id] = (4.0+pow( (*box).delta_dim[1]*(*gas).bst, 2.0) );
    }
  }
  for(num=0; num<nc; num++){
    for(i=0; i<nb; i++){
      b[cells[num].id[i]] = cells[num].n_n[i]*pow((*box).delta_dim[1],2.0);
    }
  }
*/
  // apply dirichlet BC --- first, setup the integration parameters

  // setup the parameters for ingegration
  int NNr;//(*box).N[1];//500;
  int NNphi, NNtheta;
  int nqp = 50;
  NNr = nqp;
  NNphi = nqp;
  NNtheta = nqp;
  double bb, aa, cc, dd, ee, ff;
  double *rr = (double *) malloc( NNr * sizeof(double) );
  double *phi = (double *) malloc( NNphi * sizeof(double) );
  double *theta = (double *) malloc( NNtheta * sizeof(double) );
  double *dtheta = (double *) malloc( NNtheta * sizeof(double) );
  double *dphi = (double *) malloc( NNphi * sizeof(double) );
  double *delt_r = (double *) malloc( NNr * sizeof(double) );
   aa = 0.0;
   bb = 3.0*(*gas).sigma;
   cc = 0.0;
   dd = 2*pi;
   ee = 0.0;
   ff = pi;
  double xxi[50] = {-0.9988664,  -0.99403197, -0.98535408, -0.97286439, -0.95661096, -0.93665662,
                   -0.91307856, -0.88596798, -0.85542977, -0.82158207, -0.78455583, -0.7444943,
                   -0.70155247, -0.65589647, -0.60770293, -0.5571583 , -0.50445814, -0.44980633,
                   -0.39341431, -0.33550025, -0.27628819, -0.21600724, -0.15489059, -0.0931747,
                   -0.03109834,  0.03109834,  0.0931747 ,  0.15489059,  0.21600724,  0.27628819,
                   0.33550025 , 0.39341431 , 0.44980633 , 0.50445814 , 0.5571583  , 0.60770293,
                   0.65589647 , 0.70155247 , 0.7444943  , 0.78455583 , 0.82158207 , 0.85542977,
                   0.88596798 , 0.91307856 , 0.93665662 , 0.95661096 , 0.97286439 , 0.98535408,
                   0.99403197 , 0.9988664};
  double wwi[50] = {0.00290862, 0.0067598,  0.01059055, 0.01438082, 0.01811556, 0.02178024,
  0.02536067, 0.02884299, 0.03221373, 0.03545984, 0.03856876, 0.04152846,
  0.0443275 , 0.04695505, 0.04940094, 0.0516557 , 0.05371062, 0.05555774,
  0.05718993, 0.05860085, 0.05978506, 0.06073797, 0.0614559 , 0.06193607,
  0.06217662, 0.06217662, 0.06193607, 0.0614559 , 0.06073797, 0.05978506,
  0.05860085, 0.05718993, 0.05555774, 0.05371062, 0.0516557 , 0.04940094,
  0.04695505, 0.0443275 , 0.04152846, 0.03856876, 0.03545984, 0.03221373,
  0.02884299, 0.02536067, 0.02178024, 0.01811556, 0.01438082, 0.01059055,
  0.0067598 , 0.00290862};

  for(i=0; i<NNr; i++){
    rr[i] = (bb-aa)/2.0*xxi[i]+(aa+bb)/2.0;
    delt_r[i] = wwi[i]*(bb-aa)/2.0;
  }
  for(i=0; i<NNphi; i++){
   phi[i] = (dd-cc)/2.0*xxi[i]+(cc+dd)/2.0;
   dphi[i] = wwi[i]*(dd-cc)/2.0;
  }
  for(i=0; i<NNtheta; i++){
   theta[i] = (ff-ee)/2.0*xxi[i]+(ff+ee)/2.0;
   dtheta[i] = wwi[i]*(ff-ee)/2.0;
  }

  ///// then, apply the BC in the equations
  // Lower wall
  iids[0] = 0; iids[1] = 1;
  for(jj=0; jj<(*box).N[0]; jj++){
    num = 0*(*box).N[0] + jj;
    for(id=0; id<2; id++){
      i = cells[num].id[iids[id]];
      for(j=0;j<nn;j++){
        A[i][j] = 0.0;
      }
      A[i][i] = 1.0;
      b[i] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[iids[id]], cells[num].y_n[iids[id]], rr, delt_r, phi, dphi, theta, dtheta, NNr, NNphi, NNtheta);
    }
  }
  // Upper wall
  iids[0] = 2; iids[1] = 3;
  for(jj=0; jj<(*box).N[0]; jj++){
    num = ((*box).N[1]-1)*(*box).N[0] + jj;
    for(id=0; id<2; id++){
      i = cells[num].id[iids[id]];
      for(j=0;j<nn;j++){
        A[i][j] = 0.0;
      }
      A[i][i] = 1.0;
      b[i] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[iids[id]], cells[num].y_n[iids[id]], rr, delt_r, phi, dphi, theta, dtheta, NNr, NNphi, NNtheta);
    }
  }

  // Left wall
  iids[0] = 0; iids[1] = 2;
  for(jj=0; jj<(*box).N[1]; jj++){
    num = jj*(*box).N[0] + 0;
    for(id=0; id<2; id++){
      i = cells[num].id[iids[id]];
      for(j=0;j<nn;j++){
        A[i][j] = 0.0;
      }
      A[i][i] = 1.0;
      b[i] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[iids[id]], cells[num].y_n[iids[id]], rr, delt_r, phi, dphi, theta, dtheta, NNr, NNphi, NNtheta);
    }
  }
  // Right wall
  iids[0] = 1; iids[1] = 3;
  for(jj=0; jj<(*box).N[1]; jj++){
    num = jj*(*box).N[0] + (*box).N[0]-1;
    for(id=0; id<2; id++){
      i = cells[num].id[iids[id]];
      for(j=0;j<nn;j++){
        A[i][j] = 0.0;
      }
      A[i][i] = 1.0;
      b[i] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[iids[id]], cells[num].y_n[iids[id]], rr, delt_r, phi, dphi, theta, dtheta, NNr, NNphi, NNtheta);
    }
  }

  double tol = 1e-15;
  int nnz;
  nnz = compute_num_nonzeros(A, nn, tol);
  double *a = new double[nnz];
  int *ja = new int[nnz];
  int *ia = new int[nn+1];
  transform_A_compact(A, nn, ia, ja, a, nnz, tol);
  // solve the system with sparse storage
  int error =  solver_pardiso(ia, ja, a, nn, b, x);
  // compute the residual
  double res = 0.0, res0=0.0, dummy;
  /*
  for(i=0; i<nn; i++){
    dummy = 0.0;
    for(j=0; j<nn; j++){
      dummy += A[i][j]*x[j];
    }
    res += pow(dummy - b[i],2);
  }
  for(i=0; i<nn; i++){
    res0 += x[i]*x[i];
  }
  */
  //printf("rel res = %e\n", res/res0);

  ///       compute the exact solution xe and the relative error for the system
  //for(i=0; i<(*box).N[0]+1; i++){
  //  for(j=0; j<(*box).N[1]+1; j++){
  //    id = i*((*box).N[0]+1) + j;
  //    xe[id] = sin(2.0*pi*i*cells[0].dx/(*box).Len[0])*sin(2.0*pi*j*cells[0].dy/(*box).Len[1]);
  //  }
  //}
  /*
  for(num=0; num<nc; num++){
    for(i=0; i<nb; i++){
      xe[cells[num].id[i]] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[i], cells[num].y_n[i],0.0,3.0*(*gas).sigma);
    }
  }
  dummy = 0.0, res0 = 0.0;
  for(i=0;i<nn;i++){
    dummy += pow(x[i]-xe[i],2);
    res0 += pow(xe[i],2);
  }
  printf("rel error = %e\n", dummy/res0);
  */

  // substract int_{r\in(0,sigma)} from the computed potential
  dummy = 1.0-((*gas).sigma*(*gas).bst+1.0)*exp( -(*gas).bst*(*gas).sigma );
  dummy = dummy/(*gas).bst/(*gas).bst;

  double dummy2 = (-1.0/6.0*pow((*gas).bst, 3)*pow((*gas).sigma, 3) - 1.0/2.0*pow((*gas).bst, 2)*pow((*gas).sigma, 2) - (*gas).bst*(*gas).sigma + exp((*gas).bst*(*gas).sigma) - 1)*exp(-(*gas).bst*(*gas).sigma)/pow((*gas).bst, 4);
  dummy2 = dummy2/pow((*box).delta_dim[0],2);
  //printf("dummy=%e\n", dummy);
  double d1,d2,d3;
  int ll;
  int ipm[4], jpm[4], kpm[4];
  for(j=0; j < (*box).N[1]+1; j++){
    for(i=0; i < (*box).N[0]+1; i++){
      id = j*((*box).N[0]+1)+i;
      ii = i;
      jj = j;
      k = 0;

      ipm[0]=0;ipm[1]=-1;ipm[2]=0; ipm[3]=0;
      jpm[0]=0;jpm[1]=0; jpm[2]=0; jpm[3]=-1;
      kpm[0]=1;kpm[1]=0; kpm[2]=2; kpm[3]=0;
      if(i==(*box).N[0]){
        ii = i-1;
        jj = j;
        k = 1;
        kpm[0]=k;
      }
      if(j==(*box).N[1]){
        ii = i;
        jj = j-1;
        k = 2;
        kpm[2]=k;
      }
      if(i==(*box).N[0] && j==(*box).N[1]){
        ii = i-1;
        jj = j-1;
        k = 3;
        kpm[0]=k;
        kpm[2]=k;
      }
      if(i==0){
        ipm[1]=0;
        jpm[1]=0;
        kpm[1]=0;
      }
      if(j==0){
        ipm[3]=0;
        jpm[3]=0;
        kpm[3]=0;
      }
      num = jj*(*box).N[0]+ii;
      d2 =  cells[num].n_n[k]*dummy;
      d3 =  -4.0*cells[num].n_n[k]*dummy2;
      for(ll=0; ll<4; ll++){
          num = (jj+jpm[ll])*(*box).N[0]+ii+ipm[ll];
          d3 += cells[num].n_n[kpm[ll]]*dummy2;
      }
   		x[id] +=  -(d2 + d3);
     }
  }

  // computing the total potential directly for error study
/*
  for(num=0; num<nc; num++){
    for(i=0; i<nb; i++){
      xe[cells[num].id[i]] = Compute_SP_using_Green_Function(gas, box, cells, cells[num].x_n[i], cells[num].y_n[i],(*gas).sigma,3.0*(*gas).sigma);
    }
  }
  dummy = 0.0, res0 = 0.0;
  for(i=0;i<nn;i++){
    dummy += pow(x[i]-xe[i],2);
    res0 += pow(xe[i],2);
  }
  printf("rel error = %e\n", dummy/res0);
  */
  double xi, eta, F1, F2;
  for(i=0; i<(*gas).N; i++){
    num = index[i];
    xi  = (x1[i]-cells[num].x_n[0])/cells[num].dx;
    eta = (x2[i]-cells[num].y_n[0])/cells[num].dy;
    F1 = 0.0; F2 = 0.0;
    for(j=0;j<nb;j++){
      F1 += dNxi(j,xi,eta)*x[cells[num].id[j]];
      F2 += dNeta(j,xi,eta)*x[cells[num].id[j]];
    }
    F1 = F1/(*gas).m*(*gas).ast/cells[num].dx; F2 = F2/(*gas).m*(*gas).ast/cells[num].dy;
    U1[i] = U1[i] - F1*(*gas).delta_t;
    U2[i] = U2[i] - F2*(*gas).delta_t;
  }

  //## and then clean up would be:
  // release A
    for(i = 0; i < nn; ++i) {
      delete [] A[i];
    }
    delete [] A;
  for(i = 0; i < nb; ++i) {
    delete [] dudv[i];
    delete [] uv[i];
  }
  delete [] uv;
  delete [] dudv;


  delete [] x;
  delete [] b;
  delete [] v;
  delete [] ia;
  delete [] ja;
  delete [] a;

  delete [] xe;

  free(rr); free(phi); free(theta);
  free(delt_r); free(dphi); free(dtheta);
}


void compute_Vlasov_2D(struct GAS *gas, struct BOX *box, struct CELLS *cells, double *x1, double *x2, double *U1, double *U2, int *index){
  int nn = ((*box).N[0]+1)*((*box).N[1]+1);
  int nc = (*box).N[0]*(*box).N[1];
  int nb = 4;
  int i,j,id, ii, jj, num, k;
  double *x = new double[nn];


  // setup the parameters for ingegration
  double pi = acos(-1.0);
  int NNr;
  int NNphi, NNtheta;
  int nqp = 100;
  NNr = nqp;
  NNphi = nqp;
  NNtheta = nqp;
  double bb, aa, cc, dd, ee, ff;
  double *rr = (double *) malloc( NNr * sizeof(double) );
  double *phi = (double *) malloc( NNphi * sizeof(double) );
  double *theta = (double *) malloc( NNtheta * sizeof(double) );
  double *dtheta = (double *) malloc( NNtheta * sizeof(double) );
  double *dphi = (double *) malloc( NNphi * sizeof(double) );
  double *delt_r = (double *) malloc( NNr * sizeof(double) );
   aa = 1.0*(*gas).sigma;
   bb = 3.0*(*gas).sigma;
   cc = 0.0;
   dd = 2*pi;
   ee = 0.0;
   ff = pi;

   double xxi[100]={-0.9997137267734413, -0.9984919506395958, -0.9962951347331251, -0.9931249370374434, -0.9889843952429918, -0.983877540706057, -0.9778093584869183, -0.9707857757637064, -0.9628136542558156, -0.9539007829254917, -0.944055870136256, -0.9332885350430795, -0.921609298145334, -0.9090295709825297, -0.895561644970727, -0.8812186793850184, -0.8660146884971647, -0.8499645278795913, -0.8330838798884008, -0.8153892383391762, -0.7968978923903145, -0.7776279096494955, -0.7575981185197072, -0.7368280898020207, -0.7153381175730564, -0.693149199355802, -0.670283015603141, -0.6467619085141293, -0.6226088602037078, -0.5978474702471788, -0.5725019326213812, -0.5465970120650941, -0.520158019881763, -0.49321078920819095, -0.465781649773358, -0.4378974021720315, -0.40958529167830154, -0.38087298162462996, -0.3517885263724217, -0.32236034390052914, -0.292617188038472, -0.2625881203715035, -0.23230248184497396, -0.20178986409573602, -0.17108008053860327, -0.14020313723611397, -0.10918920358006111, -0.07806858281343663, -0.046871682421591634, -0.015628984421543084, 0.015628984421543084, 0.046871682421591634, 0.07806858281343663, 0.10918920358006111, 0.14020313723611397, 0.17108008053860327, 0.20178986409573602, 0.23230248184497396, 0.2625881203715035, 0.292617188038472, 0.32236034390052914, 0.3517885263724217, 0.38087298162462996, 0.40958529167830154, 0.4378974021720315, 0.465781649773358, 0.49321078920819095, 0.520158019881763, 0.5465970120650941, 0.5725019326213812, 0.5978474702471788, 0.6226088602037078, 0.6467619085141293, 0.670283015603141, 0.693149199355802, 0.7153381175730564, 0.7368280898020207, 0.7575981185197072, 0.7776279096494955, 0.7968978923903145, 0.8153892383391762, 0.8330838798884008, 0.8499645278795913, 0.8660146884971647, 0.8812186793850184, 0.895561644970727, 0.9090295709825297, 0.921609298145334, 0.9332885350430795, 0.944055870136256, 0.9539007829254917, 0.9628136542558156, 0.9707857757637064, 0.9778093584869183, 0.983877540706057, 0.9889843952429918, 0.9931249370374434, 0.9962951347331251, 0.9984919506395958, 0.9997137267734413};
   double wwi[100]={0.0007346344905008809, 0.001709392653517807, 0.002683925371554019, 0.003655961201327216, 0.004624450063421818, 0.005588428003865117, 0.00654694845084515, 0.007499073255464816, 0.008443871469668721, 0.009380419653694542, 0.01030780257486916, 0.01122511402318622, 0.012131457662979251, 0.013025947892971715, 0.01390771070371885, 0.014775884527441474, 0.015629621077546098, 0.01646808617614516, 0.017290460568323632, 0.018095940722128407, 0.018883739613374886, 0.01965308749443545, 0.020403232646209593, 0.021133442112527594, 0.02184300241624754, 0.02253122025633626, 0.02319742318525442, 0.023840960265968263, 0.024461202707957153, 0.025057544481579718, 0.025629402910208283, 0.02617621923954582, 0.02669745918357113, 0.02719261344657694, 0.027661198220792507, 0.028102755659101357, 0.028516854322395237, 0.028903089601125278, 0.029261084110638446, 0.029590488059912694, 0.02989097959333295, 0.03016226510516929, 0.030404079526454932, 0.030616186583980524, 0.03079837903115269, 0.030950478850491105, 0.03107233742756666, 0.031163835696210035, 0.03122488425484948, 0.03125542345386349, 0.03125542345386349, 0.03122488425484948, 0.031163835696210035, 0.03107233742756666, 0.030950478850491105, 0.03079837903115269, 0.030616186583980524, 0.030404079526454932, 0.03016226510516929, 0.02989097959333295, 0.029590488059912694, 0.029261084110638446, 0.028903089601125278, 0.028516854322395237, 0.028102755659101357, 0.027661198220792507, 0.02719261344657694, 0.02669745918357113, 0.02617621923954582, 0.025629402910208283, 0.025057544481579718, 0.024461202707957153, 0.023840960265968263, 0.02319742318525442, 0.02253122025633626, 0.02184300241624754, 0.021133442112527594, 0.020403232646209593, 0.01965308749443545, 0.018883739613374886, 0.018095940722128407, 0.017290460568323632, 0.01646808617614516, 0.015629621077546098, 0.014775884527441474, 0.01390771070371885, 0.013025947892971715, 0.012131457662979251, 0.01122511402318622, 0.01030780257486916, 0.009380419653694542, 0.008443871469668721, 0.007499073255464816, 0.00654694845084515, 0.005588428003865117, 0.004624450063421818, 0.003655961201327216, 0.002683925371554019, 0.001709392653517807, 0.0007346344905008809};

/*
  double xxi[50] = {-0.9988664,  -0.99403197, -0.98535408, -0.97286439, -0.95661096, -0.93665662,
                   -0.91307856, -0.88596798, -0.85542977, -0.82158207, -0.78455583, -0.7444943,
                   -0.70155247, -0.65589647, -0.60770293, -0.5571583 , -0.50445814, -0.44980633,
                   -0.39341431, -0.33550025, -0.27628819, -0.21600724, -0.15489059, -0.0931747,
                   -0.03109834,  0.03109834,  0.0931747 ,  0.15489059,  0.21600724,  0.27628819,
                   0.33550025 , 0.39341431 , 0.44980633 , 0.50445814 , 0.5571583  , 0.60770293,
                   0.65589647 , 0.70155247 , 0.7444943  , 0.78455583 , 0.82158207 , 0.85542977,
                   0.88596798 , 0.91307856 , 0.93665662 , 0.95661096 , 0.97286439 , 0.98535408,
                   0.99403197 , 0.9988664};
  double wwi[50] = {0.00290862, 0.0067598,  0.01059055, 0.01438082, 0.01811556, 0.02178024,
  0.02536067, 0.02884299, 0.03221373, 0.03545984, 0.03856876, 0.04152846,
  0.0443275 , 0.04695505, 0.04940094, 0.0516557 , 0.05371062, 0.05555774,
  0.05718993, 0.05860085, 0.05978506, 0.06073797, 0.0614559 , 0.06193607,
  0.06217662, 0.06217662, 0.06193607, 0.0614559 , 0.06073797, 0.05978506,
  0.05860085, 0.05718993, 0.05555774, 0.05371062, 0.0516557 , 0.04940094,
  0.04695505, 0.0443275 , 0.04152846, 0.03856876, 0.03545984, 0.03221373,
  0.02884299, 0.02536067, 0.02178024, 0.01811556, 0.01438082, 0.01059055,
  0.0067598 , 0.00290862};
*/
  for(i=0; i<NNr; i++){
    rr[i] = (bb-aa)/2.0*xxi[i]+(aa+bb)/2.0;
    delt_r[i] = wwi[i]*(bb-aa)/2.0;
  }
  for(i=0; i<NNphi; i++){
   phi[i] = (dd-cc)/2.0*xxi[i]+(cc+dd)/2.0;
   dphi[i] = wwi[i]*(dd-cc)/2.0;
  }
  for(i=0; i<NNtheta; i++){
   theta[i] = (ff-ee)/2.0*xxi[i]+(ff+ee)/2.0;
   dtheta[i] = wwi[i]*(ff-ee)/2.0;
  }


  // compute Vlasov integral for each node
  for(j=0; j < (*box).N[1]+1; j++){
    for(i=0; i < (*box).N[0]+1; i++){
      id = j*((*box).N[0]+1)+i;
      ii = i;
      jj = j;
      k = 0;
      if(i==(*box).N[0]){
        ii = i-1;
        jj = j;
        k = 1;
      }
      if(j==(*box).N[1]){
        ii = i;
        jj = j-1;
        k = 2;
      }
      if(i==(*box).N[0] && j==(*box).N[1]){
        ii = i-1;
        jj = j-1;
        k = 3;
      }
      num = jj*(*box).N[0]+ii;
 		  x[id] = vlasov_taking_the_integral_2D(gas, box, cells, cells[num].x_n[k], cells[num].y_n[k], rr, delt_r, phi, dphi, theta, dtheta, NNr, NNphi, NNtheta);
     }
  }


  double xi, eta, F1, F2;
  for(i=0; i<(*gas).N; i++){
    num = index[i];
    xi  = (x1[i]-cells[num].x_n[0])/cells[num].dx;
    eta = (x2[i]-cells[num].y_n[0])/cells[num].dy;
    F1 = 0.0; F2 = 0.0;
    for(j=0;j<nb;j++){
      F1 += dNxi(j,xi,eta)*x[cells[num].id[j]];
      F2 += dNeta(j,xi,eta)*x[cells[num].id[j]];
    }
    F1 = F1/(*gas).m*(*gas).phi/cells[num].dx; F2 = F2/(*gas).m*(*gas).phi/cells[num].dy;
    U1[i] = U1[i] - F1*(*gas).delta_t;
    U2[i] = U2[i] - F2*(*gas).delta_t;
  }
  delete [] x;

  free(rr); free(phi); free(theta);
  free(delt_r); free(dphi); free(dtheta);
}

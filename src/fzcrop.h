#ifndef FZCROP_H
#define FZCROP_H

#include<list>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<Rcpp.h>

const float no_data = -99;
const float pi= 3.14159265359;
const float Gsc = 0.082;

#define FZY_OR 1
#define FZY_AND 2
#define FZY_CROP_MONTHLY 30
#define FZY_CROP_WEEKLY 7
#define DAY_OF_END_YEAR 360

using namespace Rcpp;

//fuzzy
typedef struct PARAMETER {
    int Gmin, Gmax;
    float Tkill, Tmin, Topmin, Topmax, Tmax;
    float Rmin, Ropmin, Ropmax, Rmax;
} parameter;

typedef struct SuitVars {
    float TI;
    float RN;
    float GR;
} suitvars;

typedef struct WXDATA {
    float tmax;
    float tmin;
    float prcp;
} wxdata;

float GetMedian(float* daArray, int iSize);
float THBox(float tmax, float tmin, float Tmin, float Topmin, float Topmax, float Tmax);
float Bell(float x, float* params);
float WeightedGaussian(float x, float* params);
float Trapezoid(float x, float Pmin, float POPmin, float POPmax, float Pmax);
float fzsuit(wxdata* wxdata, parameter params, int season, int durpr,
             int npr, int mode, float irrig = 0);
float calcsuit(suitvars* fvar, int mode);
float Suitrun(wxdata* climdata, parameter params, int resol, int mode, float irrig = 0);
float ecocropK(NumericVector inparams, NumericVector Tmax, NumericVector Tmin, NumericVector Prcp, LogicalVector rainfed);
#endif

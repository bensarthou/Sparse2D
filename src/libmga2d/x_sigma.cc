//sigma (scale, direction)
//              direction = [isotrope, 2 dir, 4 dir, 8 dir]
//              case TO_PAVE_FFT
/*float x_sigma[3][15] = {
                      {0.968,                            //s=0, d=0
                       0.684, 0.684,                     //s=0, d=0,1
                       0.5168, 0.4482, 0.5168, 0.4482,   //s=0, d=0,1,2,3
                       0.3305, 0.3973, 0.3305, 0.3025,   //s=0, d=0,1,2,3
                       0.3305, 0.3973, 0.3305, 0.3025},  //s=0, d=4,5,6,7
                      {0.1129,                           //s=1, d=0
                       0.0798, 0.0798,                   //s=1, d=0,1
                       0.0564, 0.0564, 0.0564, 0.0564,   //s=1, d=0,1,2,3
                       0.0400, 0.0399, 0.0400, 0.0399,   //s=1, d=0,1,2,3
                       0.0401, 0.0398, 0.0401, 0.0398},  //s=1, d=4,5,6,7
                      {0.04838,                          //s=2, d=0
                       0.0342, 0.0342,                   //s=2, d=0,1
                       0.0241, 0.0241, 0.0241, 0.0241,   //s=2, d=1,2,3,4
                       0.0172, 0.0168, 0.0171, 0.0169,
                       0.0174, 0.0168, 0.0173, 0.0170}};
*/                       
//              case TO_PAVE_BSPLINE
float x_sigma_2d[7][3];
float x_sigma_4d[7][7] = {
                      {0.889434,                            
                       0.628196,     0.628336,
                       0.488156,     0.395381,     0.488149,     0.395615},     
                      {0.200105,                            
                       0.142203,     0.142427,
                       0.101295,    0.0997964,     0.101377,     0.100034},    
                      {0.0857724,                           
                       0.0609073,    0.0609534,
                       0.0431049,    0.0430144,    0.0430951,    0.0430883},   
                      {0.0417449,
     0.0294892,    0.0295416,
     0.0208080,    0.0208884,    0.0208940,    0.0208773},
                      {0.0210340,
     0.0148431,    0.0148945,
     0.0104185,    0.0105586,    0.0104998,    0.0105504},
                      {0.0108973,
    0.00769974,   0.00769585,
    0.00526015,   0.00560001,   0.00530664,   0.00554756},
                      {0.00599390,
    0.00428358,   0.00415845,
    0.00303925,   0.00297781,   0.00292741,   0.00291578}};
                         
float x_sigma_8d[7][15] = {
                      {0.889434,  
                       0.627870,     0.627976,
                       0.478482,     0.406533,     0.478473,     0.406708,
                       0.301735,     0.371342,     0.301494,     0.272696,
                       0.301579,     0.371456,     0.301700,     0.272730},
                      {0.200105,   
                       0.142182,     0.142447,
                       0.101026,     0.100040,     0.101075,     0.100367,
                       0.0715662,    0.0712969,    0.0714649,    0.0699922,
                       0.0716241,    0.0713070,    0.0716561,    0.0702667},
                      {0.0857724,     
                       0.0608850,    0.0609767,
                       0.0430215,    0.0430661,    0.0430589,    0.0431603,
                       0.0308602,    0.0299557,    0.0307549,    0.0301278,
                       0.0308513,    0.0300171,    0.0308045,    0.0302081},
                      {0.0421,
                       0.0296532,    0.0299183,
                       0.0207837,    0.0211219,    0.0210637,    0.0212188,
                       0.0151978,    0.0141430,    0.0151879,    0.0146333,
                       0.0153198,    0.0144137,    0.0152460,    0.0147226},
                      {0.0215,
                       0.0151975,    0.0153463,
                       0.0105837,    0.0108485,    0.0107930,    0.0108554,
                       0.00805188,   0.00678880,   0.00803022,   0.00722555,
                       0.00809825,   0.00705713,   0.00808454,   0.00717619},
                      {0.0115,
                       0.00815413,   0.00815907,
                       0.00546078,   0.00597398,   0.00550762,   0.00593013,
                       0.00409821,   0.00349078,   0.00414161,   0.00419407,
                       0.00423615,   0.00337699,   0.00418596,   0.00411631},
                      {0.0063,
                       0.00447165,   0.00447458,
                       0.00284428,   0.00332890,   0.00281250,   0.00337144,
                       0.00154378,   0.00228098,   0.00154979,   0.00288381,
                       0.00153999,   0.00223319,   0.00166358,   0.00286422}};

float x_sigma_16d[7][31] = {
                      {0.889434,                            
                       0.627669,     0.627866,
      0.465173,     0.421398,     0.465432,     0.421406,
      0.288078,     0.365226,     0.320120,     0.274028,
      0.288051,     0.365575,     0.319911,     0.274285,
      0.195690,     0.211391,     0.240366,     0.274969,
      0.240774,     0.210946,     0.195823,     0.191674,
      0.195913,     0.211152,     0.240399,     0.275400,
      0.239995,     0.211513,     0.195962,     0.191902},     
                      {0.200105,                            
                       0.142251,     0.142378,
      0.100896,     0.100269,     0.100840,     0.100506,
     0.0709374,    0.0717365,    0.0713798,    0.0704070,
     0.0708607,    0.0717346,    0.0715283,    0.0705944,
     0.0498967,    0.0504079,    0.0507043,    0.0507322,
     0.0506087,    0.0503221,    0.0498214,    0.0497349,
     0.0497650,    0.0504261,    0.0506576,    0.0507753,
     0.0507358,    0.0504033,    0.0499060,    0.0499140},    
                      {0.0857724,                           
                        0.0609404,    0.0609205,
     0.0431110,    0.0430557,    0.0430255,    0.0431132,
     0.0305460,    0.0304035,    0.0304052,    0.0304635,
     0.0304805,    0.0303466,    0.0304718,    0.0304796,
     0.0215779,    0.0215961,    0.0215514,    0.0214153,
     0.0214920,    0.0214855,    0.0216495,    0.0214011,
     0.0214322,    0.0216461,    0.0214442,    0.0214458,
     0.0216094,    0.0214579,    0.0216259,    0.0214508},   
                      {0.0423,
                       0.0296643,    0.0299078,
     0.0210471,    0.0208780,    0.0212519,    0.0210136,
     0.0149882,    0.0147413,    0.0145917,    0.0148948,
     0.0150551,    0.0149647,    0.0147591,    0.0149232,
     0.0108215,    0.0103235,    0.0104714,    0.0103169,
     0.0102916,    0.0102956,    0.0108840,    0.0101065,
     0.0109043,    0.0103209,    0.0105256,    0.0105758,
     0.0105024,    0.0103239,    0.0109201,    0.0101087},
                      {0.0216250,
     0.0151902,    0.0153548,
     0.0105339,    0.0108916,    0.0106445,    0.0110159,
    0.00762470,   0.00719909,   0.00754472,   0.00778347,
    0.00765576,   0.00732309,   0.00773661,   0.00777268,
    0.00506680,   0.00560949,   0.00511486,   0.00496857,
    0.00497191,   0.00558786,   0.00517856,   0.00572030,
    0.00510192,   0.00563634,   0.00517441,   0.00508007,
    0.00525015,   0.00559084,   0.00521269,   0.00566789},
                      {0.0115809,
    0.00815692,   0.00815632,
    0.00548633,   0.00595418,   0.00552530,   0.00590853,
    0.00380053,   0.00385612,   0.00394131,   0.00435378,
    0.00396539,   0.00371817,   0.00397419,   0.00428514,
    0.00168723,   0.00335580,   0.00185592,   0.00329408,
    0.00183644,   0.00341580,   0.00168643,   0.00396947,
    0.00165821,   0.00355068,   0.00179138,   0.00316362,
    0.00185089,   0.00343573,   0.00173324,   0.00387994},
                      {0.00637925,
    0.00447486,   0.00447204,
    0.00289669,   0.00328783,   0.00286226,   0.00332613,
    0.00158367,   0.00231555,   0.00144819,   0.00289420,
    0.00157776,   0.00226407,   0.00155175,   0.00287873,
   0.000789163,   0.00135741,  0.000392668,   0.00226925,
   0.000376670,   0.00138075,  0.000749571,   0.00277193,
   0.000746722,   0.00137192,  0.000368605,   0.00222153,
   0.000384432,   0.00148516,  0.000816150,   0.00273571}};                   
		       
                         		      
		                     
float x_sigma_32d[7][63] = {
                      {0.889434,                            
                       0.627618,     0.627774,
      0.455565,     0.431693,     0.455848,     0.431622,
      0.282990,     0.357001,     0.331982,     0.275933,
      0.282971,     0.357374,     0.331691,     0.276174,
      0.194227,     0.205798,     0.231594,     0.271673,
      0.251583,     0.216591,     0.198519,     0.191629,
      0.194381,     0.205625,     0.231557,     0.272197,
      0.250935,     0.216895,     0.198869,     0.191618,
      0.135696,     0.138932,     0.142016,     0.148921,
      0.157770,     0.169522,     0.184908,     0.199019,
      0.185473,     0.169959,     0.157340,     0.148828,
      0.141833,     0.138876,     0.135776,     0.135203,
      0.135640,     0.139208,     0.141939,     0.148759,
      0.157642,     0.169591,     0.185176,     0.199479,
      0.185011,     0.169507,     0.157315,     0.149294,
      0.141912,     0.139296,     0.135419,     0.135543},     
                      {0.200105,                            
                       0.142296,     0.142333,
      0.100843,     0.100386,     0.100756,     0.100526,
     0.0709303,    0.0716699,    0.0714683,    0.0704847,
     0.0707414,    0.0717346,    0.0715527,    0.0705980,
     0.0503258,    0.0499668,    0.0505920,    0.0507487,
     0.0508809,    0.0501741,    0.0499564,    0.0497072,
     0.0500333,    0.0499944,    0.0506654,    0.0507655,
     0.0508868,    0.0502865,    0.0500861,    0.0497400,
     0.0354897,    0.0356604,    0.0350144,    0.0356294,
     0.0354232,    0.0360968,    0.0360416,    0.0357088,
     0.0359054,    0.0360311,    0.0355065,    0.0354268,
     0.0349732,    0.0356509,    0.0351870,    0.0350857,
     0.0350793,    0.0356487,    0.0350358,    0.0356453,
     0.0354885,    0.0361391,    0.0358672,    0.0359070,
     0.0357434,    0.0361993,    0.0355107,    0.0355859,
     0.0350289,    0.0357812,    0.0351668,    0.0351551},    
                      {0.0857724,                           
                       0.0609717,    0.0608886,
     0.0432406,    0.0429682,    0.0430791,    0.0430159,
     0.0306199,    0.0305134,    0.0302799,    0.0304634,
     0.0304840,    0.0304192,    0.0303837,    0.0304280,
     0.0220342,    0.0212339,    0.0215618,    0.0215647,
     0.0216432,    0.0211500,    0.0216260,    0.0214300,
     0.0218759,    0.0212053,    0.0215073,    0.0214866,
     0.0218061,    0.0211308,    0.0216336,    0.0213729,
     0.0154896,    0.0156348,    0.0148339,    0.0151498,
     0.0149510,    0.0154931,    0.0151734,    0.0152888,
     0.0150287,    0.0155427,    0.0149137,    0.0149490,
     0.0147754,    0.0157581,    0.0155016,    0.0147494,
     0.0152905,    0.0156102,    0.0147583,    0.0151851,
     0.0147733,    0.0155927,    0.0151327,    0.0152119,
     0.0151727,    0.0156250,    0.0148378,    0.0150075,
     0.0148346,    0.0157084,    0.0154418,    0.0147399},   
                      {0.0421372,
     0.0296674,    0.0299045,
     0.0208125,    0.0211159,    0.0209851,    0.0212769,
     0.0147320,    0.0146660,    0.0147728,    0.0150519,
     0.0147814,    0.0148560,    0.0149781,    0.0150787,
     0.0106830,    0.0100889,    0.0103287,    0.0103651,
     0.0105976,    0.0102324,    0.0104421,    0.0107865,
     0.0107778,    0.0100593,    0.0104382,    0.0105203,
     0.0108611,    0.0102610,    0.0103961,    0.0108672,
    0.00740337,   0.00763336,   0.00689549,   0.00729611,
    0.00706329,   0.00744878,   0.00767309,   0.00689406,
    0.00757722,   0.00734075,   0.00708816,   0.00729642,
    0.00688738,   0.00778014,   0.00742388,   0.00774136,
    0.00729468,   0.00785421,   0.00683746,   0.00729596,
    0.00705689,   0.00761813,   0.00773973,   0.00704994,
    0.00778154,   0.00749370,   0.00707039,   0.00735149,
    0.00682012,   0.00777642,   0.00750314,   0.00779045
                       },
                      {0.0216250,
     0.0151901,    0.0153546,
     0.0104785,    0.0109463,    0.0105847,    0.0110719,
    0.00674458,   0.00795206,   0.00702696,   0.00833170,
    0.00679651,   0.00804794,   0.00724512,   0.00830205,
    0.00490266,   0.00454155,   0.00545320,   0.00568043,
    0.00503406,   0.00480562,   0.00566319,   0.00601684,
    0.00495305,   0.00457714,   0.00550433,   0.00578401,
    0.00531013,   0.00482552,   0.00565739,   0.00598890,
    0.00231359,   0.00427648,   0.00336202,   0.00292339,
    0.00379304,   0.00379007,   0.00337499,   0.00447342,
    0.00333122,   0.00365280,   0.00375036,   0.00285127,
    0.00343689,   0.00437987,   0.00236498,   0.00549628,
    0.00228970,   0.00433784,   0.00343119,   0.00286086,
    0.00377467,   0.00389604,   0.00339568,   0.00457362,
    0.00360454,   0.00374640,   0.00372707,   0.00292779,
    0.00338711,   0.00441358,   0.00240237,   0.00544674
                       },
                      {0.0115809,
    0.00815840,   0.00815489,
    0.00552724,   0.00591795,   0.00556370,   0.00587040,
    0.00270890,   0.00475295,   0.00335987,   0.00476907,
    0.00275787,   0.00475721,   0.00336100,   0.00472132,
    0.00174917,   0.00200507,   0.00318364,   0.00338866,
    0.00183187,   0.00271837,   0.00250670,   0.00397706,
    0.00171927,   0.00208145,   0.00330188,   0.00326203,
    0.00184642,   0.00270508,   0.00257147,   0.00388764,
   0.000961496,   0.00144726,   0.00182466,  0.000752435,
    0.00259607,   0.00165265,  0.000745487,   0.00328559,
   0.000742283,   0.00162868,   0.00259121,  0.000733003,
    0.00194416,   0.00145428,  0.000945863,   0.00384569,
   0.000931610,   0.00143031,   0.00192152,  0.000718841,
    0.00277386,   0.00159470,  0.000713879,   0.00315474,
   0.000753547,   0.00163089,   0.00258102,  0.000718835,
    0.00200477,   0.00150043,  0.000969177,   0.00374855
                       },
                      {0.00637925,
    0.00447688,   0.00447048,
    0.00292732,   0.00326355,   0.00289101,   0.00329911,
    0.00110289,   0.00267509,   0.00130416,   0.00294188,
    0.00105197,   0.00264754,   0.00139168,   0.00293516,
   0.000867503,  0.000678436,   0.00124591,   0.00227362,
   0.000376216,   0.00122754,  0.000866836,   0.00277958,
   0.000819297,  0.000656677,   0.00126276,   0.00222579,
   0.000383968,   0.00131626,  0.000945275,   0.00274575,
   0.000589544,  0.000636029,  0.000633863,  0.000214028,
    0.00116868,  0.000364870,  0.000133412,   0.00226732,
   0.000132430,  0.000347514,   0.00120260,  0.000203913,
   0.000621242,  0.000601902,  0.000559760,   0.00270609,
   0.000556775,  0.000600545,  0.000614597,  0.000202674,
    0.00119532,  0.000340012,  0.000130758,   0.00221962,
   0.000131331,  0.000356435,   0.00129095,  0.000211452,
   0.000676864,  0.000657431,  0.000607329,   0.00266013
                       }};   
		                        
float x_sigma_64d[7][127] = {
                      {0.889434,                            
                       },     
                      {0.200105,                            
                       },    
                      {0.0857724,                           
                       },   
                      {0.0423,
                       },
                      {0.0217,
                       },
                      {0.0116,
                       },
                      {0.0061,
                       }};         





float x_sigma_overlap_2d[7][3];
float x_sigma_overlap_4d[7][7] = {
{      1.78082,
       1.04091,      1.04062,
      0.598497,     0.573303,     0.598197,     0.573353},
{     0.401805,
      0.235688,     0.235496,
      0.133118,     0.132741,     0.132956,     0.132734},
{     0.171699,
      0.100629,     0.100679,
     0.0567718,    0.0567718,    0.0568198,    0.0567675},
{    0.0835240,
     0.0488552,    0.0489988,
     0.0275499,    0.0276184,    0.0276623,    0.0276331},
{    0.0421587,
     0.0246789,    0.0247683,
     0.0138616,    0.0139602,    0.0139501,    0.0139518},
{    0.0217659,
     0.0127903,    0.0127579,
    0.00716317,   0.00722242,   0.00717303,   0.00718240},
{    0.0119237,
    0.00703611,   0.00683386,
    0.00394259,   0.00396274,   0.00381536,   0.00390689}};

 
float x_sigma_overlap_8d[7][15];
float x_sigma_overlap_16d[7][31] = {
{      1.78084,
       1.22021,      1.22027,
      0.849371,     0.771521,     0.849467,     0.771531,
      0.479557,     0.604130,     0.533367,     0.455803,
      0.479729,     0.604170,     0.533288,     0.455816,
      0.261227,     0.281997,     0.322191,     0.351261,
      0.322363,     0.282103,     0.261113,     0.254889,
      0.261186,     0.282121,     0.322192,     0.351363,
      0.322343,     0.282148,     0.261125,     0.255016},
{     0.401901,
      0.273150,     0.272973,
      0.185254,     0.184015,     0.185122,     0.183933,
      0.117631,     0.118873,     0.118360,     0.116664,
      0.117423,     0.118891,     0.118039,     0.116727,
     0.0661920,    0.0664971,    0.0668899,    0.0671349,
     0.0669898,    0.0664725,    0.0659161,    0.0657200,
     0.0659666,    0.0664609,    0.0669306,    0.0670902,
     0.0667730,    0.0664152,    0.0660003,    0.0658210},
{     0.171810,
      0.116637,     0.116631,
     0.0790024,    0.0787581,    0.0789020,    0.0789230,
     0.0503348,    0.0505348,    0.0504305,    0.0502122,
     0.0503375,    0.0503165,    0.0503660,    0.0502589,
     0.0284842,    0.0283668,    0.0284808,    0.0285063,
     0.0284953,    0.0283282,    0.0282553,    0.0283542,
     0.0283680,    0.0284301,    0.0284273,    0.0283417,
     0.0283477,    0.0284761,    0.0284022,    0.0283994},
{    0.0836146,
     0.0566382,    0.0568313,
     0.0383169,    0.0383057,    0.0385310,    0.0383626,
     0.0244465,    0.0245054,    0.0243442,    0.0245990,
     0.0246123,    0.0245248,    0.0243634,    0.0245968,
     0.0138784,    0.0137286,    0.0137977,    0.0138172,
     0.0137418,    0.0137123,    0.0137996,    0.0138921,
     0.0138760,    0.0138845,    0.0138857,    0.0137898,
     0.0137658,    0.0137400,    0.0138264,    0.0139254},
{    0.0421551,
     0.0283715,    0.0287327,
     0.0189597,    0.0193820,    0.0192772,    0.0195882,
     0.0121624,    0.0120397,    0.0123134,    0.0124020,
     0.0124586,    0.0121449,    0.0125860,    0.0124401,
    0.00689749,   0.00680872,   0.00675490,   0.00683936,
    0.00692405,   0.00695785,   0.00693822,   0.00703964,
    0.00705610,   0.00696291,   0.00687966,   0.00683426,
    0.00704919,   0.00707755,   0.00696373,   0.00704207},
{    0.0216286,
     0.0146030,    0.0145954,
    0.00970204,    0.0100013,   0.00959273,    0.0100508,
    0.00626911,   0.00607827,   0.00626023,   0.00628198,
    0.00607053,   0.00614428,   0.00642399,   0.00631642,
    0.00347076,   0.00351819,   0.00340995,   0.00342816,
    0.00343166,   0.00365638,   0.00358860,   0.00348230,
    0.00336994,   0.00344085,   0.00341860,   0.00350763,
    0.00357651,   0.00364244,   0.00351093,   0.00356202},
{    0.0117699,
    0.00799649,   0.00769776,
    0.00526756,   0.00545306,   0.00509462,   0.00520129,
    0.00331155,   0.00330339,   0.00342221,   0.00360713,
    0.00311564,   0.00318422,   0.00317265,   0.00353128,
    0.00178455,   0.00197910,   0.00184696,   0.00184756,
    0.00184258,   0.00194008,   0.00179109,   0.00216170,
    0.00169158,   0.00191765,   0.00183646,   0.00176824,
    0.00171239,   0.00182404,   0.00174137,   0.00213767}};

float x_sigma_overlap_32d[7][63];
float x_sigma_overlap_64d[7][127];
// airspy-fmradion
// Software decoder for FM broadcast radio with Airspy
//
// Copyright (C) 2019 Kenji Rikitake, JJ1BDX
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "FilterParameters.h"
#include "SoftFM.h"

// Values of vectors

const IQSampleCoeff FilterParameters::jj1bdx_10000khz_div8 = {
    1.1051074176443457e-05,  -2.887126573751125e-05, -0.00013296146408847928,
    -0.000368080684577711,   -0.0008012860766448335, -0.001493723525097442,
    -0.002475757709236189,   -0.003716914254326066,  -0.005096054095138254,
    -0.006379570171960038,   -0.007215643489859813,  -0.007152334674409715,
    -0.005682245065159621,   -0.002312592750035461,  0.003347573015295875,
    0.01149629711269656,     0.022060865074942853,   0.034650510447037756,
    0.04855362972868346,     0.0627865078321344,     0.0761916566319153,
    0.08757375774845268,     0.09585329019692942,    0.10021309139181349,
    0.10021309139181349,     0.09585329019692942,    0.08757375774845268,
    0.0761916566319153,      0.0627865078321344,     0.04855362972868346,
    0.034650510447037756,    0.022060865074942853,   0.01149629711269656,
    0.003347573015295875,    -0.002312592750035461,  -0.005682245065159621,
    -0.007152334674409715,   -0.007215643489859813,  -0.006379570171960038,
    -0.005096054095138254,   -0.003716914254326066,  -0.002475757709236189,
    -0.001493723525097442,   -0.0008012860766448335, -0.000368080684577711,
    -0.00013296146408847928, -2.887126573751125e-05, 1.1051074176443457e-05};

const IQSampleCoeff FilterParameters::jj1bdx_6000khz_div5 = {
    2.114902479137389e-06, 1.3903278208217198e-05, 5.359409637910289e-05,
    0.0001529651931077227, 0.0003517307409287276,  0.0006762978401835756,
    0.00110058355849211,   0.001497814943473998,   0.001607161342343259,
    0.001050113228351605,  -0.0005712034755232094, -0.003485218569377297,
    -0.007505866020639915, -0.011813666194382455,  -0.014875480513321365,
    -0.014604324307719282, -0.008797520925183353,  0.004211534981050231,
    0.024860304863846057,  0.05185989885700086,    0.08211426785079898,
    0.11116818627616132,   0.13412558721512297,    0.14680677073968929,
    0.14680677073968929,   0.13412558721512297,    0.11116818627616132,
    0.08211426785079898,   0.05185989885700086,    0.024860304863846057,
    0.004211534981050231,  -0.008797520925183353,  -0.014604324307719282,
    -0.014875480513321365, -0.011813666194382455,  -0.007505866020639915,
    -0.003485218569377297, -0.0005712034755232094, 0.001050113228351605,
    0.001607161342343259,  0.001497814943473998,   0.00110058355849211,
    0.0006762978401835756, 0.0003517307409287276,  0.0001529651931077227,
    5.359409637910289e-05, 1.3903278208217198e-05, 2.114902479137389e-06};

const IQSampleCoeff FilterParameters::jj1bdx_1250khz_div4 = {
    1.705663202339406e-05,   7.090996428217538e-05,   0.00013272441223895158,
    0.00020366689984283856,  0.0002288662261528966,   0.00016275456793812048,
    -3.406293726898602e-05,  -0.00035167346272952987, -0.0007132619941101718,
    -0.0009728127546395046,  -0.0009525624782331736,  -0.0005130658991775068,
    0.00036107230092931607,  0.001496411731094055,    0.002525911107233368,
    0.002971071375294049,    0.002406990651962229,    0.0006667442170308879,
    -0.001990995076918853,   -0.00483682369768822,    -0.006807926206962522,
    -0.006828805842355561,   -0.004239731179904641,   0.0008089446660580263,
    0.007164092204926444,    0.012811075172987494,    0.01538487078587691,
    0.012955256910043764,    0.004865458833899867,    -0.007663642550064061,
    -0.021426490737281388,   -0.03176155943043012,    -0.03366020604534061,
    -0.023196102246412387,   0.001128081783930766,    0.037546005931513984,
    0.08102071376871225,     0.12415372636805637,     0.15882375549444028,
    0.1781342539421179,      0.1781342539421179,      0.15882375549444028,
    0.12415372636805637,     0.08102071376871225,     0.037546005931513984,
    0.001128081783930766,    -0.023196102246412387,   -0.03366020604534061,
    -0.03176155943043012,    -0.021426490737281388,   -0.007663642550064061,
    0.004865458833899867,    0.012955256910043764,    0.01538487078587691,
    0.012811075172987494,    0.007164092204926444,    0.0008089446660580263,
    -0.004239731179904641,   -0.006828805842355561,   -0.006807926206962522,
    -0.00483682369768822,    -0.001990995076918853,   0.0006667442170308879,
    0.002406990651962229,    0.002971071375294049,    0.002525911107233368,
    0.001496411731094055,    0.00036107230092931607,  -0.0005130658991775068,
    -0.0009525624782331736,  -0.0009728127546395046,  -0.0007132619941101718,
    -0.00035167346272952987, -3.406293726898602e-05,  0.00016275456793812048,
    0.0002288662261528966,   0.00020366689984283856,  0.00013272441223895158,
    7.090996428217538e-05,   1.705663202339406e-05};

const IQSampleCoeff FilterParameters::jj1bdx_2500khz_div4 = {
    3.123472772264273e-06,  8.219920396555278e-06,   1.2770476419393305e-06,
    -5.464969019206663e-05, -0.00020819385033657504, -0.0004707090580549312,
    -0.0007374076985133128, -0.0007329208786117031,  -6.963407682626804e-05,
    0.001517957519640194,   0.003808687608677464,    0.005801252425086564,
    0.005790453519935745,   0.002032176939903518,    -0.006080268383706677,
    -0.016808826182478573,  -0.02558063458970376,    -0.025851904469395733,
    -0.011400956287771912,  0.020675055599770845,    0.06759617938691287,
    0.12050801920440773,    0.16666345190034557,     0.19358719650082468,
    0.19358719650082468,    0.16666345190034557,     0.12050801920440773,
    0.06759617938691287,    0.020675055599770845,    -0.011400956287771912,
    -0.025851904469395733,  -0.02558063458970376,    -0.016808826182478573,
    -0.006080268383706677,  0.002032176939903518,    0.005790453519935745,
    0.005801252425086564,   0.003808687608677464,    0.001517957519640194,
    -6.963407682626804e-05, -0.0007329208786117031,  -0.0007374076985133128,
    -0.0004707090580549312, -0.00020819385033657504, -5.464969019206663e-05,
    1.2770476419393305e-06, 8.219920396555278e-06,   3.123472772264273e-06};

const IQSampleCoeff FilterParameters::jj1bdx_625khz_div2 = {
    6.19150959468886e-05,    0.00011779779550217712,  -1.0418060970322838e-05,
    -0.0002972138096031444,  -0.0002788149654787191,  0.0003353639547416378,
    0.0008061333607011767,   3.262959775671989e-05,   -0.001405790291546753,
    -0.001148999388536154,   0.001447384806139054,    0.002903002649292676,
    -0.00018537682685089023, -0.004607316486686131,   -0.002958530522228064,
    0.004793157709172084,    0.007617297184752642,    -0.001771256960947082,
    -0.012121811277480268,   -0.005612783452440522,   0.013396335750295871,
    0.016830571434653174,    -0.007712151923099555,   -0.02899874913125388,
    -0.008389205197846295,   0.03652587773095992,     0.037621042199956586,
    -0.030514953004122936,   -0.08541539008816218,    -0.010190760673140828,
    0.19680614997223456,     0.3822540130736618,      0.3822540130736618,
    0.19680614997223456,     -0.010190760673140828,   -0.08541539008816218,
    -0.030514953004122936,   0.037621042199956586,    0.03652587773095992,
    -0.008389205197846295,   -0.02899874913125388,    -0.007712151923099555,
    0.016830571434653174,    0.013396335750295871,    -0.005612783452440522,
    -0.012121811277480268,   -0.001771256960947082,   0.007617297184752642,
    0.004793157709172084,    -0.002958530522228064,   -0.004607316486686131,
    -0.00018537682685089023, 0.002903002649292676,    0.001447384806139054,
    -0.001148999388536154,   -0.001405790291546753,   3.262959775671989e-05,
    0.0008061333607011767,   0.0003353639547416378,   -0.0002788149654787191,
    -0.0002972138096031444,  -1.0418060970322838e-05, 0.00011779779550217712,
    6.19150959468886e-05};

const IQSampleCoeff FilterParameters::jj1bdx_768khz_div2 = {
    1.596366011034184e-05,   -3.135031931804697e-05, -0.0001474744526865472,
    -0.00028709355041271983, -0.0002905352578333242, 1.1612881984393283e-05,
    0.0005960178952203278,   0.001099335598005876,   0.0009436562550028023,
    -0.00020895447571864023, -0.00194197698944086,   -0.00301069798487988,
    -0.002045917211644354,   0.001224205881922208,   0.005136004107149769,
    0.006616272817146359,    0.003237323903949671,   -0.004360602408887024,
    -0.011665411001623662,   -0.012477975037706368,  -0.003412267137891191,
    0.012169938593057282,    0.024229805266695867,   0.021502049521202715,
    -8.731833636414345e-05,  -0.03143507329267592,   -0.05178773321483239,
    -0.03872735607873677,    0.018129060264815804,   0.1078978824868809,
    0.20025583428432678,     0.25872756223303695,    0.25872756223303695,
    0.20025583428432678,     0.1078978824868809,     0.018129060264815804,
    -0.03872735607873677,    -0.05178773321483239,   -0.03143507329267592,
    -8.731833636414345e-05,  0.021502049521202715,   0.024229805266695867,
    0.012169938593057282,    -0.003412267137891191,  -0.012477975037706368,
    -0.011665411001623662,   -0.004360602408887024,  0.003237323903949671,
    0.006616272817146359,    0.005136004107149769,   0.001224205881922208,
    -0.002045917211644354,   -0.00301069798487988,   -0.00194197698944086,
    -0.00020895447571864023, 0.0009436562550028023,  0.001099335598005876,
    0.0005960178952203278,   1.1612881984393283e-05, -0.0002905352578333242,
    -0.00028709355041271983, -0.0001474744526865472, -3.135031931804697e-05,
    1.596366011034184e-05};

const IQSampleCoeff FilterParameters::jj1bdx_900khz_div3 = {
    -6.404935389267344e-05,  -0.0001414264373988809,  -0.00016953751582107817,
    -3.3527318198777426e-05, 0.0003092578747862682,   0.0007165724322452014,
    0.0008509471076203169,   0.0003647366679327649,   -0.0007715937488801656,
    -0.002024822150248085,   -0.002420304851345945,   -0.00112923829215776,
    0.001745816267759424,    0.004765604224078176,    0.005657361850048007,
    0.002733066219516793,    -0.003521150242209262,   -0.009875177690084405,
    -0.011662756419917916,   -0.005698431707985977,   0.006784362260926866,
    0.019329632846358018,    0.022913208611499942,    0.011348799353070966,
    -0.013362935318499117,   -0.03928117328371791,    -0.048455331508202096,
    -0.025508290448475145,   0.03322506041364377,     0.11515148303775125,
    0.19470566541323522,     0.2436573564433936,      0.2436573564433936,
    0.19470566541323522,     0.11515148303775125,     0.03322506041364377,
    -0.025508290448475145,   -0.048455331508202096,   -0.03928117328371791,
    -0.013362935318499117,   0.011348799353070966,    0.022913208611499942,
    0.019329632846358018,    0.006784362260926866,    -0.005698431707985977,
    -0.011662756419917916,   -0.009875177690084405,   -0.003521150242209262,
    0.002733066219516793,    0.005657361850048007,    0.004765604224078176,
    0.001745816267759424,    -0.00112923829215776,    -0.002420304851345945,
    -0.002024822150248085,   -0.0007715937488801656,  0.0003647366679327649,
    0.0008509471076203169,   0.0007165724322452014,   0.0003092578747862682,
    -3.3527318198777426e-05, -0.00016953751582107817, -0.0001414264373988809,
    -6.404935389267344e-05};

const IQSampleCoeff FilterParameters::delay_3taps_only_iq = {0.0, 1.0, 0.0};

const SampleCoeff FilterParameters::jj1bdx_48khz_fmaudio = {
    1.0101538343156901e-07, 4.394677230260367e-08,   -3.867158920421356e-07,
    4.550052394054024e-07,  4.2243654992168073e-07,  -1.856700371603661e-06,
    1.7934350372596484e-06, 1.581254861883408e-06,   -6.2784747656576516e-06,
    5.931773638356052e-06,  3.982344028958351e-06,   -1.7231590082734962e-05,
    1.7065223192421945e-05, 7.382174740440623e-06,   -4.0682996129477794e-05,
    4.358600141367943e-05,  9.195040741247982e-06,   -8.515627693862435e-05,
    0.00010040324103675794, 1.5981992887546445e-06,  -0.00016078215760171103,
    0.00021129524742604535, -3.2773013221760905e-05, -0.0002764935315405614,
    0.00041047891049814496, -0.00012630646790063595, -0.0004347458475390368,
    0.0007423262560244399,  -0.00033236137157121513, -0.0006235223291951401,
    0.00125816987219327,    -0.00073059156112438,    -0.0008059395274708236,
    0.002009548506148357,   -0.001430554048668224,   -0.0009082607253514219,
    0.003038070993085482,   -0.002573250100039745,   -0.000807083857179171,
    0.00436318072483048,    -0.004332187299585962,   -0.00031511214188372877,
    0.005970194984670549,   -0.006919561383197073,   0.0008393142144861044,
    0.007801688326274638,   -0.010611734486741495,   0.003054970449284701,
    0.009755248438222308,   -0.01583021907267296,    0.006971293162796619,
    0.011689683862289075,   -0.023386678731854738,   0.013816714320254317,
    0.01344001113410461,    -0.03531376594813095,    0.026709264037950382,
    0.014839390885081113,   -0.05870991929335667,    0.05790659491111103,
    0.01574420285787947,    -0.14413657831559104,    0.2668229209259829,
    0.6827239283565725,     0.2668229209259829,      -0.14413657831559104,
    0.01574420285787947,    0.05790659491111103,     -0.05870991929335667,
    0.014839390885081113,   0.026709264037950382,    -0.03531376594813095,
    0.01344001113410461,    0.013816714320254317,    -0.023386678731854738,
    0.011689683862289075,   0.006971293162796619,    -0.01583021907267296,
    0.009755248438222308,   0.003054970449284701,    -0.010611734486741495,
    0.007801688326274638,   0.0008393142144861044,   -0.006919561383197073,
    0.005970194984670549,   -0.00031511214188372877, -0.004332187299585962,
    0.00436318072483048,    -0.000807083857179171,   -0.002573250100039745,
    0.003038070993085482,   -0.0009082607253514219,  -0.001430554048668224,
    0.002009548506148357,   -0.0008059395274708236,  -0.00073059156112438,
    0.00125816987219327,    -0.0006235223291951401,  -0.00033236137157121513,
    0.0007423262560244399,  -0.0004347458475390368,  -0.00012630646790063595,
    0.00041047891049814496, -0.0002764935315405614,  -3.2773013221760905e-05,
    0.00021129524742604535, -0.00016078215760171103, 1.5981992887546445e-06,
    0.00010040324103675794, -8.515627693862435e-05,  9.195040741247982e-06,
    4.358600141367943e-05,  -4.0682996129477794e-05, 7.382174740440623e-06,
    1.7065223192421945e-05, -1.7231590082734962e-05, 3.982344028958351e-06,
    5.931773638356052e-06,  -6.2784747656576516e-06, 1.581254861883408e-06,
    1.7934350372596484e-06, -1.856700371603661e-06,  4.2243654992168073e-07,
    4.550052394054024e-07,  -3.867158920421356e-07,  4.394677230260367e-08,
    1.0101538343156901e-07};

const SampleCoeff FilterParameters::delay_3taps_only_audio = {0.0, 1.0, 0.0};

const IQSampleCoeff FilterParameters::jj1bdx_am_if_div2 = {
    2.2844015853646287e-05, 0.00047902120145814546, 0.003301480770006667,
    0.012862289249679913,   0.03424212643798773,    0.06796110870285849,
    0.10524450782600622,    0.1302774968852405,     0.1302774968852405,
    0.10524450782600622,    0.06796110870285849,    0.03424212643798773,
    0.012862289249679913,   0.003301480770006667,   0.00047902120145814546,
    2.2844015853646287e-05};

const IQSampleCoeff FilterParameters::jj1bdx_am_if_div3 = {
    2.2844015853646287e-05, 0.00047902120145814546, 0.003301480770006667,
    0.012862289249679913,   0.03424212643798773,    0.06796110870285849,
    0.10524450782600622,    0.1302774968852405,     0.1302774968852405,
    0.10524450782600622,    0.06796110870285849,    0.03424212643798773,
    0.012862289249679913,   0.003301480770006667,   0.00047902120145814546,
    2.2844015853646287e-05};

const IQSampleCoeff FilterParameters::jj1bdx_am_if_div4 = {
    3.797187136566095e-05,  0.00014300956789776255, 0.00021129517450689468,
    -0.0002697027543395223, -0.002212263904001054,  -0.006137043248894018,
    -0.010543196676393782,  -0.010526200558175212,  0.001478667905288858,
    0.031789709716850745,   0.07994260425244391,    0.1354471969699831,
    0.18039293741667078,    0.19771508636708543,    0.18039293741667078,
    0.1354471969699831,     0.07994260425244391,    0.031789709716850745,
    0.001478667905288858,   -0.010526200558175212,  -0.010543196676393782,
    -0.006137043248894018,  -0.002212263904001054,  -0.0002697027543395223,
    0.00021129517450689468, 0.00014300956789776255, 3.797187136566095e-05};
const IQSampleCoeff FilterParameters::jj1bdx_am_if_div5 = {
    6.870338705065754e-08,   -5.531219679353777e-06, -4.113440433643013e-05,
    -0.00017930394585423515, -0.0005386292255356865, -0.001222848311858347,
    -0.002161015320597352,   -0.002875721657756961,  -0.002290203506798189,
    0.00125472815470995,     0.00963288738957557,    0.024213833627570576,
    0.04501430899180066,     0.07009790209194287,    0.09561380015946873,
    0.1166226925505358,      0.1285166241986948,     0.1285166241986948,
    0.1166226925505358,      0.09561380015946873,    0.07009790209194287,
    0.04501430899180066,     0.024213833627570576,   0.00963288738957557,
    0.00125472815470995,     -0.002290203506798189,  -0.002875721657756961,
    -0.002161015320597352,   -0.001222848311858347,  -0.0005386292255356865,
    -0.00017930394585423515, -4.113440433643013e-05, -5.531219679353777e-06,
    6.870338705065754e-08};

const IQSampleCoeff FilterParameters::jj1bdx_am_if_div7 = {
    1.5448661616160648e-06,  -1.0907887202365494e-05, -3.1288159059424475e-05,
    -8.471112321588164e-05,  -0.0001954818101106861,  -0.00039256478581315405,
    -0.0007001633575400831,  -0.001120798227372359,   -0.001612555701729144,
    -0.002063734860397902,   -0.002271764724784142,   -0.00193561731977271,
    -0.0006703553883282213,  0.001951039752037597,    0.006328219318870927,
    0.012745204079735626,    0.021277778040080575,    0.03171825280020214,
    0.043538344164150214,    0.055909959952280854,    0.06778173467011266,
    0.07801186735182704,     0.08553498377170903,     0.08951981012951038,
    0.08951981012951038,     0.08553498377170903,     0.07801186735182704,
    0.06778173467011266,     0.055909959952280854,    0.043538344164150214,
    0.03171825280020214,     0.021277778040080575,    0.012745204079735626,
    0.006328219318870927,    0.001951039752037597,    -0.0006703553883282213,
    -0.00193561731977271,    -0.002271764724784142,   -0.002063734860397902,
    -0.001612555701729144,   -0.001120798227372359,   -0.0007001633575400831,
    -0.00039256478581315405, -0.0001954818101106861,  -8.471112321588164e-05,
    -3.1288159059424475e-05, -1.0907887202365494e-05, 1.5448661616160648e-06};

const IQSampleCoeff FilterParameters::jj1bdx_am_48khz_div2 = {
    -2.1557749540677755e-05, -0.00026298784160905963, -0.000244656585374534,
    0.00163915607544259,     0.002312213007481242,    -0.005317440697384818,
    -0.009963275188428492,   0.011789752040298517,    0.030474414722226936,
    -0.01989887971026985,    -0.08201547781873064,    0.026840692176531417,
    0.3094529378739175,      0.47040981097684065,     0.3094529378739175,
    0.026840692176531417,    -0.08201547781873064,    -0.01989887971026985,
    0.030474414722226936,    0.011789752040298517,    -0.009963275188428492,
    -0.005317440697384818,   0.002312213007481242,    0.00163915607544259,
    -0.000244656585374534,   -0.00026298784160905963, -2.1557749540677755e-05};

const IQSampleCoeff FilterParameters::jj1bdx_am_24khz_div2 = {
    3.445830092942331e-06,   -5.644307314991841e-06,  -5.530944011295581e-05,
    -9.343272039020056e-05,  2.458187954716842e-05,   0.00025652561922692377,
    0.00019478798807174766,  -0.00038446815858387445, -0.0007671157722096562,
    6.27246549896222e-05,    0.001494598206730199,    0.001163435662507894,
    -0.001626920216272209,   -0.00329114871151908,    2.1875745348611627e-05,
    0.00528452102168947,     0.004093008762411334,    -0.004968972731241279,
    -0.009994951642875128,   -0.00015136979898069415, 0.0146665494778572,
    0.011215483337956652,    -0.01306177503879877,    -0.02617226879239932,
    -0.00041090632701697643, 0.03871041764672663,     0.030298875502124286,
    -0.037692955811471494,   -0.08227776697024775,    -0.0006081867704993952,
    0.19970702162524054,     0.3743130405240938,      0.3743130405240938,
    0.19970702162524054,     -0.0006081867704993952,  -0.08227776697024775,
    -0.037692955811471494,   0.030298875502124286,    0.03871041764672663,
    -0.00041090632701697643, -0.02617226879239932,    -0.01306177503879877,
    0.011215483337956652,    0.0146665494778572,      -0.00015136979898069415,
    -0.009994951642875128,   -0.004968972731241279,   0.004093008762411334,
    0.00528452102168947,     2.1875745348611627e-05,  -0.00329114871151908,
    -0.001626920216272209,   0.001163435662507894,    0.001494598206730199,
    6.27246549896222e-05,    -0.0007671157722096562,  -0.00038446815858387445,
    0.00019478798807174766,  0.00025652561922692377,  2.458187954716842e-05,
    -9.343272039020056e-05,  -5.530944011295581e-05,  -5.644307314991841e-06,
    3.445830092942331e-06};

const IQSampleCoeff FilterParameters::jj1bdx_am_12khz_middle = {
    -6.024944095703265e-06, -0.00017931162824769145, -0.00011431446302848314,
    0.000346690056638064,   1.2978193147444568e-05,  -0.0006911231210873327,
    0.00039802230543592475, 0.0009922733407839515,   -0.001300694645672108,
    -0.0008465357976464866, 0.002633349795237466,    -0.0002994579709377263,
    -0.003881928179643443,  0.002860297905595254,    0.00400804584048921,
    -0.00667082811272287,   -0.001681781369186393,   0.010581460701172211,
    -0.004136807046125633,  -0.012345988949021282,   0.013412393492528384,
    0.008972014037977604,   -0.024342205808966462,   0.002557129985728608,
    0.033005692384700254,   -0.02471001980828292,    -0.033095503235051886,
    0.060466323725188065,   0.01308309589230889,     -0.12387236877148777,
    0.07896201046738097,    0.5057383246672115,      0.5057383246672115,
    0.07896201046738097,    -0.12387236877148777,    0.01308309589230889,
    0.060466323725188065,   -0.033095503235051886,   -0.02471001980828292,
    0.033005692384700254,   0.002557129985728608,    -0.024342205808966462,
    0.008972014037977604,   0.013412393492528384,    -0.012345988949021282,
    -0.004136807046125633,  0.010581460701172211,    -0.001681781369186393,
    -0.00667082811272287,   0.00400804584048921,     0.002860297905595254,
    -0.003881928179643443,  -0.0002994579709377263,  0.002633349795237466,
    -0.0008465357976464866, -0.001300694645672108,   0.0009922733407839515,
    0.00039802230543592475, -0.0006911231210873327,  1.2978193147444568e-05,
    0.000346690056638064,   -0.00011431446302848314, -0.00017931162824769145,
    -6.024944095703265e-06};

const IQSampleCoeff FilterParameters::jj1bdx_am_12khz_narrow = {
    5.71525632536046e-05,    0.00019218907422306387, 0.00013089244573528445,
    -0.00025136352445842715, -0.0004933404028342243, 7.750383103951407e-05,
    0.0009744029284217767,   0.0006101163562844877,  -0.001215392754241679,
    -0.001883442809560081,   0.0006385185345325043,  0.00339810549659771,
    0.001304193713296104,    -0.004263973455985988,  -0.004718683796596493,
    0.003189359422835115,    0.008844809952980672,   0.001042610379955156,
    -0.011857715353388927,   -0.008866728152723675,  0.011074409790223456,
    0.019245637275917958,    -0.003555785030132795,  -0.02925938742052663,
    -0.013214355941609024,   0.03397564683503437,    0.04140622507017953,
    -0.025570615848760025,   -0.08659110659795333,   -0.016041669060514054,
    0.19470901567040824,     0.3870462376433521,     0.3870462376433521,
    0.19470901567040824,     -0.016041669060514054,  -0.08659110659795333,
    -0.025570615848760025,   0.04140622507017953,    0.03397564683503437,
    -0.013214355941609024,   -0.02925938742052663,   -0.003555785030132795,
    0.019245637275917958,    0.011074409790223456,   -0.008866728152723675,
    -0.011857715353388927,   0.001042610379955156,   0.008844809952980672,
    0.003189359422835115,    -0.004718683796596493,  -0.004263973455985988,
    0.001304193713296104,    0.00339810549659771,    0.0006385185345325043,
    -0.001883442809560081,   -0.001215392754241679,  0.0006101163562844877,
    0.0009744029284217767,   7.750383103951407e-05,  -0.0004933404028342243,
    -0.00025136352445842715, 0.00013089244573528445, 0.00019218907422306387,
    5.71525632536046e-05};

const IQSampleCoeff FilterParameters::jj1bdx_ssb_3to6khz = {
    1.1185441217322993e-05,  1.4772084885333002e-05,  -7.175623998317038e-05,
    0.00011203784389752994,  -7.390089761442054e-05,  4.542211737423359e-06,
    -3.0486835163728348e-05, 0.00014836929695382473,  -0.00016578262772604617,
    -6.319470407652892e-06,  0.0001316914968175806,   1.6978857931614357e-05,
    -0.00019233875245465082, -4.016464108786073e-05,  0.000517962107564149,
    -0.000563422128815299,   0.00011473138835573602,  -7.400558640659199e-05,
    0.0008951071509163112,   -0.001538186572775309,   0.0009508270117548105,
    -6.530444158111247e-05,  0.0006328901912345533,   -0.002126883513679377,
    0.002031863725820845,    1.4663274656305937e-05,  -0.000950251340769239,
    -0.0009025992830352011,  0.002313936707009511,    0.0001381917755065805,
    -0.003763496963871954,   0.003202043408196648,    0.00034477103042194584,
    0.00021814972740405043,  -0.006177534670046089,   0.009258987628936972,
    -0.004552831139681726,   0.00016544530164545177,  -0.005196536128362702,
    0.013286856821979005,    -0.010800200521080524,   -2.519400931811676e-05,
    0.001907190319405288,    0.009189033050061147,    -0.013934025575081666,
    -0.00024214364291939337, 0.015035072579693073,    -0.007989184607084756,
    -0.007740786452945269,   -0.00032244261113911163, 0.029250276797307805,
    -0.03807182851752401,    0.013382803319389833,    -0.0001843295017501194,
    0.03420124603915904,     -0.07381167512468839,    0.054266154670154665,
    9.262773161601451e-05,   0.00993446781923131,     -0.10303974491681082,
    0.143927698522825,       0.00031222598817716527,  -0.25619684218892325,
    0.3856663716494966,      -0.25619684218892325,    0.00031222598817716527,
    0.143927698522825,       -0.10303974491681082,    0.00993446781923131,
    9.262773161601451e-05,   0.054266154670154665,    -0.07381167512468839,
    0.03420124603915904,     -0.0001843295017501194,  0.013382803319389833,
    -0.03807182851752401,    0.029250276797307805,    -0.00032244261113911163,
    -0.007740786452945269,   -0.007989184607084756,   0.015035072579693073,
    -0.00024214364291939337, -0.013934025575081666,   0.009189033050061147,
    0.001907190319405288,    -2.519400931811676e-05,  -0.010800200521080524,
    0.013286856821979005,    -0.005196536128362702,   0.00016544530164545177,
    -0.004552831139681726,   0.009258987628936972,    -0.006177534670046089,
    0.00021814972740405043,  0.00034477103042194584,  0.003202043408196648,
    -0.003763496963871954,   0.0001381917755065805,   0.002313936707009511,
    -0.0009025992830352011,  -0.000950251340769239,   1.4663274656305937e-05,
    0.002031863725820845,    -0.002126883513679377,   0.0006328901912345533,
    -6.530444158111247e-05,  0.0009508270117548105,   -0.001538186572775309,
    0.0008951071509163112,   -7.400558640659199e-05,  0.00011473138835573602,
    -0.000563422128815299,   0.000517962107564149,    -4.016464108786073e-05,
    -0.00019233875245465082, 1.6978857931614357e-05,  0.0001316914968175806,
    -6.319470407652892e-06,  -0.00016578262772604617, 0.00014836929695382473,
    -3.0486835163728348e-05, 4.542211737423359e-06,   -7.390089761442054e-05,
    0.00011203784389752994,  -7.175623998317038e-05,  1.4772084885333002e-05,
    1.1185441217322993e-05};
// End of FilterParameters.cpp

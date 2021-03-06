#include <stdlib.h>

#include "audiodsp/lib/osc_core.h"
#include "audiodsp/lib/pitch_core.h"


SGFLT OSC_CORE_PHASES[32][7] = {
    {
        0.6989061,
        0.6868586,
        0.90484,
        0.5415453,
        0.9900585,
        0.3143611,
        0.0919347,
    },
    {
        0.9181428,
        0.2751784,
        0.7400948,
        0.5718263,
        0.4214851,
        0.4604448,
        0.2722325,
    },
    {
        0.7206065,
        0.0898293,
        0.4825136,
        0.7961812,
        0.8759107,
        0.8568205,
        0.4767968,
    },
    {
        0.8371948,
        0.2125657,
        0.5625259,
        0.8904409,
        0.4042453,
        0.8196843,
        0.1461114,
    },
    {
        0.4992467,
        0.5897497,
        0.8048265,
        0.0436214,
        0.6709343,
        0.7444446,
        0.6809413,
    },
    {
        0.0857547,
        0.9559251,
        0.6869634,
        0.169546,
        0.9835646,
        0.3899435,
        0.2903364,
    },
    {
        0.6134309,
        0.5856497,
        0.7563441,
        0.7587474,
        0.2134643,
        0.1738532,
        0.6018435,
    },
    {
        0.127107,
        0.2944777,
        0.6470475,
        0.4251944,
        0.7089361,
        0.8360137,
        0.3656334,
    },
    {
        0.8195233,
        0.0483403,
        0.7387587,
        0.4585367,
        0.2477873,
        0.9162572,
        0.117488,
    },
    {
        0.0336324,
        0.2160904,
        0.098294,
        0.8271136,
        0.2725742,
        0.1112417,
        0.6216311,
    },
    {
        0.4717264,
        0.9996308,
        0.4638668,
        0.4498277,
        0.1345038,
        0.154921,
        0.9569118,
    },
    {
        0.449986,
        0.4119315,
        0.534643,
        0.7334476,
        0.6527618,
        0.1719031,
        0.4280033,
    },
    {
        0.9833573,
        0.136955,
        0.1579993,
        0.1017519,
        0.7413061,
        0.5776072,
        0.6278879,
    },
    {
        0.10957,
        0.7088413,
        0.6399151,
        0.3539884,
        0.8896941,
        0.7335881,
        0.4175334,
    },
    {
        0.0314244,
        0.7120599,
        0.943309,
        0.4986112,
        0.6898419,
        0.7632111,
        0.7032073,
    },
    {
        0.7773599,
        0.0170788,
        0.5418397,
        0.1553756,
        0.4573957,
        0.8031099,
        0.7296574,
    },
    {
        0.7659461,
        0.1084456,
        0.9491461,
        0.1871249,
        0.6295168,
        0.6388573,
        0.7768097,
    },
    {
        0.1188844,
        0.0613816,
        0.7916009,
        0.0221891,
        0.8275299,
        0.6818878,
        0.8899355,
    },
    {
        0.5855486,
        0.3827664,
        0.406653,
        0.5707087,
        0.6556305,
        0.7381914,
        0.2394832,
    },
    {
        0.5745346,
        0.3610563,
        0.0234697,
        0.8841709,
        0.9421126,
        0.2799642,
        0.0723022,
    },
    {
        0.4582694,
        0.7949715,
        0.3731962,
        0.3674521,
        0.8000449,
        0.398127,
        0.8304149,
    },
    {
        0.5282662,
        0.239956,
        0.8334495,
        0.0308022,
        0.5931571,
        0.36405,
        0.3672831,
    },
    {
        0.3920326,
        0.4393126,
        0.6220584,
        0.6282668,
        0.34509,
        0.8466445,
        0.1837448,
    },
    {
        0.287984,
        0.3840699,
        0.290144,
        0.0230633,
        0.7800688,
        0.5351073,
        0.6744483,
    },
    {
        0.8406885,
        0.8969681,
        0.8321254,
        0.7758988,
        0.9756954,
        0.0144763,
        0.1016051,
    },
    {
        0.9605844,
        0.7250974,
        0.1829144,
        0.3327158,
        0.0900722,
        0.5141043,
        0.9616756,
    },
    {
        0.2539579,
        0.1276329,
        0.6247976,
        0.5016906,
        0.1933748,
        0.4084947,
        0.4040266,
    },
    {
        0.5003771,
        0.3817564,
        0.0751299,
        0.7723359,
        0.7276448,
        0.7160071,
        0.5769927,
    },
    {
        0.3655593,
        0.1603825,
        0.0156493,
        0.4052902,
        0.1588455,
        0.9229849,
        0.6674578,
    },
    {
        0.7518312,
        0.1722085,
        0.7628719,
        0.1225932,
        0.9079203,
        0.2591233,
        0.5558852,
    },
    {
        0.6255932,
        0.2613452,
        0.0987149,
        0.2923835,
        0.7108629,
        0.9921074,
        0.8310596,
    },
    {
        0.8762507,
        0.0750027,
        0.587421,
        0.132262,
        0.8156757,
        0.1498255,
        0.8890017,
    },
};

void g_init_osc_core(t_osc_core * f_result)
{
    f_result->output = 0.0f;
}

void v_osc_core_free(t_osc_core * a_osc)
{
    free(a_osc);
}

/* void v_run_osc(
 * t_osc_core *a_core,
 * SGFLT a_inc) //The increment to run the oscillator by.
 * The oscillator will increment until it reaches 1,
 * then resets to (value - 1), for each oscillation
 */
void v_run_osc(t_osc_core *a_core, SGFLT a_inc)
{
    a_core->output = (a_core->output) + a_inc;

    if(unlikely(a_core->output >= 1.0f))
    {
        a_core->output -= 1.0f;
    }
}

int v_run_osc_sync(t_osc_core *a_core, SGFLT a_inc)
{
    a_core->output += a_inc;

    if(unlikely(a_core->output >= 1.0f))
    {
        a_core->output = (a_core->output - 1.0f);
        return 1;
    }
    else
    {
        return 0;
    }
}


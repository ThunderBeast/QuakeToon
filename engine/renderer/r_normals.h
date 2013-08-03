/*
 * Copyright (C) 1997-2001 Id Software, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */


// Precalculated sines and cosines for quantized normals

static float r_sinTable[256] =
{
    0.000000,   0.024541,  0.049068,  0.073565,  0.098017,  0.122411,  0.146730,  0.170962,
    0.195090,   0.219101,  0.242980,  0.266713,  0.290285,  0.313682,  0.336890,  0.359895,
    0.382683,   0.405241,  0.427555,  0.449611,  0.471397,  0.492898,  0.514103,  0.534998,
    0.555570,   0.575808,  0.595699,  0.615232,  0.634393,  0.653173,  0.671559,  0.689541,
    0.707107,   0.724247,  0.740951,  0.757209,  0.773010,  0.788346,  0.803208,  0.817585,
    0.831470,   0.844854,  0.857729,  0.870087,  0.881921,  0.893224,  0.903989,  0.914210,
    0.923880,   0.932993,  0.941544,  0.949528,  0.956940,  0.963776,  0.970031,  0.975702,
    0.980785,   0.985278,  0.989177,  0.992480,  0.995185,  0.997290,  0.998795,  0.999699,
    1.000000,   0.999699,  0.998795,  0.997290,  0.995185,  0.992480,  0.989177,  0.985278,
    0.980785,   0.975702,  0.970031,  0.963776,  0.956940,  0.949528,  0.941544,  0.932993,
    0.923880,   0.914210,  0.903989,  0.893224,  0.881921,  0.870087,  0.857729,  0.844854,
    0.831470,   0.817585,  0.803208,  0.788346,  0.773010,  0.757209,  0.740951,  0.724247,
    0.707107,   0.689541,  0.671559,  0.653173,  0.634393,  0.615232,  0.595699,  0.575808,
    0.555570,   0.534998,  0.514103,  0.492898,  0.471397,  0.449611,  0.427555,  0.405241,
    0.382683,   0.359895,  0.336890,  0.313682,  0.290285,  0.266713,  0.242980,  0.219101,
    0.195090,   0.170962,  0.146731,  0.122411,  0.098017,  0.073564,  0.049068,  0.024541,
    -0.000000, -0.024541, -0.049068, -0.073565, -0.098017, -0.122411, -0.146730, -0.170962,
    -0.195090, -0.219101, -0.242980, -0.266713, -0.290285, -0.313682, -0.336890, -0.359895,
    -0.382683, -0.405241, -0.427555, -0.449611, -0.471397, -0.492898, -0.514103, -0.534998,
    -0.555570, -0.575808, -0.595699, -0.615232, -0.634393, -0.653173, -0.671559, -0.689541,
    -0.707107, -0.724247, -0.740951, -0.757209, -0.773010, -0.788346, -0.803208, -0.817585,
    -0.831469, -0.844853, -0.857729, -0.870087, -0.881921, -0.893224, -0.903989, -0.914210,
    -0.923880, -0.932993, -0.941544, -0.949528, -0.956940, -0.963776, -0.970031, -0.975702,
    -0.980785, -0.985278, -0.989177, -0.992480, -0.995185, -0.997290, -0.998795, -0.999699,
    -1.000000, -0.999699, -0.998795, -0.997290, -0.995185, -0.992480, -0.989177, -0.985278,
    -0.980785, -0.975702, -0.970031, -0.963776, -0.956940, -0.949528, -0.941544, -0.932993,
    -0.923879, -0.914210, -0.903989, -0.893224, -0.881921, -0.870087, -0.857729, -0.844853,
    -0.831470, -0.817585, -0.803208, -0.788346, -0.773010, -0.757209, -0.740951, -0.724247,
    -0.707107, -0.689541, -0.671559, -0.653173, -0.634393, -0.615231, -0.595699, -0.575808,
    -0.555570, -0.534998, -0.514103, -0.492898, -0.471397, -0.449612, -0.427555, -0.405241,
    -0.382683, -0.359895, -0.336890, -0.313682, -0.290285, -0.266713, -0.242980, -0.219101,
    -0.195090, -0.170962, -0.146730, -0.122411, -0.098017, -0.073565, -0.049068, -0.024541
};

static float r_cosTable[256] =
{
    1.000000,   0.999699,  0.998795,  0.997290,  0.995185,  0.992480,  0.989177,  0.985278,
    0.980785,   0.975702,  0.970031,  0.963776,  0.956940,  0.949528,  0.941544,  0.932993,
    0.923880,   0.914210,  0.903989,  0.893224,  0.881921,  0.870087,  0.857729,  0.844854,
    0.831470,   0.817585,  0.803208,  0.788346,  0.773010,  0.757209,  0.740951,  0.724247,
    0.707107,   0.689541,  0.671559,  0.653173,  0.634393,  0.615232,  0.595699,  0.575808,
    0.555570,   0.534998,  0.514103,  0.492898,  0.471397,  0.449611,  0.427555,  0.405241,
    0.382683,   0.359895,  0.336890,  0.313682,  0.290285,  0.266713,  0.242980,  0.219101,
    0.195090,   0.170962,  0.146730,  0.122411,  0.098017,  0.073565,  0.049068,  0.024541,
    -0.000000, -0.024541, -0.049068, -0.073565, -0.098017, -0.122411, -0.146730, -0.170962,
    -0.195090, -0.219101, -0.242980, -0.266713, -0.290285, -0.313682, -0.336890, -0.359895,
    -0.382683, -0.405241, -0.427555, -0.449611, -0.471397, -0.492898, -0.514103, -0.534998,
    -0.555570, -0.575808, -0.595699, -0.615232, -0.634393, -0.653173, -0.671559, -0.689541,
    -0.707107, -0.724247, -0.740951, -0.757209, -0.773010, -0.788346, -0.803208, -0.817585,
    -0.831470, -0.844854, -0.857729, -0.870087, -0.881921, -0.893224, -0.903989, -0.914210,
    -0.923880, -0.932993, -0.941544, -0.949528, -0.956940, -0.963776, -0.970031, -0.975702,
    -0.980785, -0.985278, -0.989177, -0.992480, -0.995185, -0.997290, -0.998795, -0.999699,
    -1.000000, -0.999699, -0.998795, -0.997290, -0.995185, -0.992480, -0.989177, -0.985278,
    -0.980785, -0.975702, -0.970031, -0.963776, -0.956940, -0.949528, -0.941544, -0.932993,
    -0.923880, -0.914210, -0.903989, -0.893224, -0.881921, -0.870087, -0.857729, -0.844854,
    -0.831470, -0.817585, -0.803208, -0.788346, -0.773011, -0.757209, -0.740951, -0.724247,
    -0.707107, -0.689541, -0.671559, -0.653173, -0.634393, -0.615232, -0.595699, -0.575808,
    -0.555570, -0.534998, -0.514103, -0.492898, -0.471397, -0.449611, -0.427555, -0.405242,
    -0.382684, -0.359895, -0.336890, -0.313682, -0.290285, -0.266713, -0.242980, -0.219101,
    -0.195090, -0.170962, -0.146730, -0.122411, -0.098017, -0.073565, -0.049068, -0.024541,
    0.000000,   0.024541,  0.049068,  0.073565,  0.098017,  0.122411,  0.146730,  0.170962,
    0.195090,   0.219101,  0.242980,  0.266713,  0.290285,  0.313682,  0.336890,  0.359895,
    0.382684,   0.405241,  0.427555,  0.449611,  0.471397,  0.492898,  0.514103,  0.534998,
    0.555570,   0.575808,  0.595699,  0.615232,  0.634393,  0.653173,  0.671559,  0.689540,
    0.707107,   0.724247,  0.740951,  0.757209,  0.773011,  0.788347,  0.803207,  0.817585,
    0.831470,   0.844854,  0.857729,  0.870087,  0.881921,  0.893224,  0.903989,  0.914210,
    0.923880,   0.932993,  0.941544,  0.949528,  0.956940,  0.963776,  0.970031,  0.975702,
    0.980785,   0.985278,  0.989177,  0.992480,  0.995185,  0.997290,  0.998795, 0.999699
};

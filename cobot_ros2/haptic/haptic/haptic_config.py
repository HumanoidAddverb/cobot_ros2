import numpy as np
import math

# CARTESIAN JOGGING THRESH
CART_JOG_X_THRESH_POSITIVE = 0.04
CART_JOG_X_THRESH_NEGATIVE = -0.03
CART_JOG_Y_THRESH_POSITIVE = 0.04
CART_JOG_Y_THRESH_NEGATIVE = -0.03
CART_JOG_Z_THRESH_POSITIVE = -0.21
CART_JOG_Z_THRESH_NEGATIVE = -0.2

# ROTATIONAL JOGGING THRESH
ROT_JOG_X_THRESH_POSITIVE = 0.13
ROT_JOG_X_THRESH_NEGATIVE = -0.2
ROT_JOG_Y_THRESH_POSITIVE = 0.2
ROT_JOG_Y_THRESH_NEGATIVE = -0.3
ROT_JOG_Z_THRESH_POSITIVE = 0.5
ROT_JOG_Z_THRESH_NEGATIVE = -0.5

MAX_FORCE_LIMIT = 30
MAX_TORQUE_LIMIT = 0.5

cart = (
    (CART_JOG_X_THRESH_POSITIVE, CART_JOG_X_THRESH_NEGATIVE),
    (CART_JOG_Y_THRESH_POSITIVE, CART_JOG_Y_THRESH_NEGATIVE),
    (CART_JOG_Z_THRESH_POSITIVE, CART_JOG_Z_THRESH_NEGATIVE),
)

rot = (
    (ROT_JOG_X_THRESH_POSITIVE, ROT_JOG_X_THRESH_NEGATIVE),
    (ROT_JOG_Y_THRESH_POSITIVE, ROT_JOG_Y_THRESH_NEGATIVE),
    (ROT_JOG_Z_THRESH_POSITIVE, ROT_JOG_Z_THRESH_NEGATIVE),
)

def rot_mat(x, y, z):
    """Return 3x3 rotation matrix from roll (x), pitch (y), yaw (z) in radians."""
    rot_x = np.array([
        [1, 0, 0],
        [0, math.cos(x), -math.sin(x)],
        [0, math.sin(x),  math.cos(x)]
    ])
    
    rot_y = np.array([
        [math.cos(y), 0, math.sin(y)],
        [0, 1, 0],
        [-math.sin(y), 0, math.cos(y)]
    ])
    
    rot_z = np.array([
        [math.cos(z), -math.sin(z), 0],
        [math.sin(z),  math.cos(z), 0],
        [0, 0, 1]
    ])

    # Combine rotations: R = Rz * Ry * Rx (standard intrinsic XYZ convention)
    return rot_z @ rot_y @ rot_x

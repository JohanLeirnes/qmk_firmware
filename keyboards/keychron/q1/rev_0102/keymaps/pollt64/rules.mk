VIA_ENABLE = no
MOUSEKEY_ENABLE = no
ENCODER_ENABLE = yes
TAP_DANCE_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif

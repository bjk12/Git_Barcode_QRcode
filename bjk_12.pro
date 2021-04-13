#-------------------------------------------------
#
# Project created by QtCreator 2019-11-13T08:44:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bjk_12
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += HAVE_CONFIG_H
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#CONFIG += console
CONFIG += precompile_header

PRECOMPILED_HEADER = stable.h

RESOURCES += \
    res/edit.qrc \
    res/skin.qrc

FORMS += \
    form/about.ui \
    form/main.ui

DISTFILES += \
    docimg/img1.png \
    docimg/img2.png \
    docimg/img3.png \
    docimg/img4.png \
    res/edit/arrow_redo.png \
    res/edit/arrow_undo.png \
    res/edit/attach.png \
    res/edit/book_addresses.png \
    res/edit/bullet_white.png \
    res/edit/cut.png \
    res/edit/date.png \
    res/edit/email.png \
    res/edit/group_add.png \
    res/edit/html.png \
    res/edit/page_copy.png \
    res/edit/palette.png \
    res/edit/paste_word.png \
    res/edit/r_i.png \
    res/edit/r_s.png \
    res/edit/r_w.png \
    res/edit/tag_blue.png \
    res/edit/Text.png \
    res/edit/text_align_center.png \
    res/edit/text_align_justify.png \
    res/edit/text_align_left.png \
    res/edit/text_align_right.png \
    res/edit/text_bold.png \
    res/edit/text_indent.png \
    res/edit/text_indent_remove.png \
    res/edit/text_italic.png \
    res/edit/text_list_bullets.png \
    res/edit/text_list_numbers.png \
    res/edit/text_lowercase.png \
    res/edit/text_underline.png \
    res/edit/text_uppercase.png \
    res/edit/time.png \
    res/edit/txt_list_clear.png \
    res/edit/user.png \
    res/images/bg/bg--.png \
    res/images/bg/bg.png \
    res/images/bg/client--.png \
    res/images/bg/client.png \
    res/images/cmb/combobox_hover.png \
    res/images/cmb/combobox_normal.png \
    res/images/cmb/combobox_push.png \
    res/images/cmb/comboboxlist_bkg.png \
    res/images/cmb/inputbtn_down.png \
    res/images/cmb/inputbtn_highlight.png \
    res/images/cmb/inputbtn_normal.png \
    res/images/FrameBorder/frameBorderEffect_mouseDownDraw.png \
    res/images/FrameBorder/frameBorderEffect_normalDraw.png \
    res/images/headerview/--listhead_normal.png \
    res/images/headerview/All_listctrl_arrowDown.png \
    res/images/headerview/All_listctrl_arrowUp.png \
    res/images/headerview/All_listctrl_titleLine.png \
    res/images/headerview/listhead_down.png \
    res/images/headerview/listhead_highlight.png \
    res/images/headerview/listhead_normal---.png \
    res/images/headerview/listhead_normal.png \
    res/images/headerview/listitem_even.png \
    res/images/headerview/listitem_highlight.png \
    res/images/headerview/listitem_odd.png \
    res/images/linedit/clear.png \
    res/images/ScrollBar/scrollbar_arrowdown_down.png \
    res/images/ScrollBar/scrollbar_arrowdown_highlight.png \
    res/images/ScrollBar/scrollbar_arrowdown_normal.png \
    res/images/ScrollBar/scrollbar_arrowleft_down.png \
    res/images/ScrollBar/scrollbar_arrowleft_highlight.png \
    res/images/ScrollBar/scrollbar_arrowleft_normal.png \
    res/images/ScrollBar/scrollbar_arrowright_down.png \
    res/images/ScrollBar/scrollbar_arrowright_highlight.png \
    res/images/ScrollBar/scrollbar_arrowright_normal.png \
    res/images/ScrollBar/scrollbar_arrowup_down.png \
    res/images/ScrollBar/scrollbar_arrowup_highlight.png \
    res/images/ScrollBar/scrollbar_arrowup_normal.png \
    res/images/ScrollBar/scrollbar_bar_down.png \
    res/images/ScrollBar/scrollbar_bar_highlight.png \
    res/images/ScrollBar/scrollbar_bar_normal.png \
    res/images/ScrollBar/scrollbar_bkg.png \
    res/images/ScrollBar/scrollbar_down_down.png \
    res/images/ScrollBar/scrollbar_down_highlight.png \
    res/images/ScrollBar/scrollbar_down_normal.png \
    res/images/ScrollBar/scrollbar_horz_bkg.png \
    res/images/ScrollBar/scrollbar_horzbar_down.png \
    res/images/ScrollBar/scrollbar_horzbar_highlight.png \
    res/images/ScrollBar/scrollbar_horzbar_normal.png \
    res/images/ScrollBar/scrollbar_top_down.png \
    res/images/ScrollBar/scrollbar_top_highlight.png \
    res/images/ScrollBar/scrollbar_top_normal.png \
    res/images/SpinControl/down-arrow.png \
    res/images/SpinControl/spin_highlight_down.png \
    res/images/SpinControl/spin_highlight_up.png \
    res/images/SpinControl/spin_normal_down.png \
    res/images/SpinControl/spin_normal_up.png \
    res/images/SpinControl/spin_pushed_down.png \
    res/images/SpinControl/spin_pushed_up.png \
    res/images/SpinControl/up-arrow.png \
    res/images/tip/guangdiantongtips_meterial.png \
    res/images/tip/tips.png \
    res/images/tip/tips_meterial.png \
    res/images/tip/tips_png_bkg.png \
    res/images/titlebar/bg.png \
    res/images/titlebar/close.png \
    res/images/titlebar/icon.png \
    res/images/titlebar/max.png \
    res/images/titlebar/menu.png \
    res/images/titlebar/min.png \
    res/images/titlebar/restore.png \
    res/images/titlebar/skin.png \
    res/images/TreeCtrl/expand.png \
    res/images/TreeCtrl/unExpand.png \
    res/images/btn_disabled.png \
    res/images/btn_down.png \
    res/images/btn_hover.png \
    res/images/btn_normal.png \
    res/skin.ini

INCLUDEPATH +=\
            ./inc\
            ./qrencode

SOURCES += \
    src/Base_Widget.cpp \
    src/NcFramelessHelper.cpp \
    src/Skin.cpp \
    src/State_Button.cpp \
    src/Title_Bar.cpp \
    main.cpp \
    my_widget.cpp \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrspec.c \
    qrencode/rscode.c \
    qrencode/split.c \
    qrencode/qrinput.c

HEADERS += \
    qrencode/bitstream.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rscode.h \
    qrencode/split.h \
    qrencode/config.h \
    inc/Base_Widget.h \
    inc/NcFramelessHelper.h \
    inc/Skin.h \
    inc/State_Button.h \
    inc/Title_Bar.h \
    my_widget.h\
    stable.h
RC_ICONS = 7m.ico

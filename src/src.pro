TEMPLATE = subdirs

CONFIG += ordered #按顺序编译

#ROOT_DIR = $$PWD

# 源码目录
#SRC_DIR = $$ROOT_DIR/src

# 设置 插件路径
#LIBS_DIR = $$ROOT_DIR/src/libs

# 设置 插件路径
#PLUGIN_DIR = $$ROOT_DIR/src/plugin
#message($$PLUGIN_DIR)

SUBDIRS +=  libs \
            plugin \
            main

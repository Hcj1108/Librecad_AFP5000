# -*- coding: utf-8 -*-
import sys

with open(sys.argv[1], 'r', encoding='gbk', errors='replace') as f:
    lines = f.readlines()

# 分类映射: 行号 → 日志类型
# oper = Logger::write (操作日志)
# error = Logger::writeError (错误日志)
# comm = Logger::writeComm (通信日志)
changes = {
    # 程序启停 → 操作日志
    230: 'write',      # 程序开始
    237: 'write',      # 存储空间不足，删除文件
    240: 'writeError', # 存储空间不足，删除文件失败

    # 用户登录 → 操作日志
    516: 'write',      # 未登录
    556: 'write',      # 用户名

    # 界面操作 → 操作日志
    655: 'writeComm',  # 触发拍照 → 通信
    669: 'writeComm',  # 触发拍照 → 通信
    682: 'writeError', # 取消报警 → 操作(但原文是"取消报警"特殊)
    725: 'write',      # 自定义字段
    770: 'write',      # 关闭用户界面
    789: 'write',      # 保存方案并返回
    798: 'write',      # 关闭参数设置界面
    861: 'write',      # 保存方案并返回
    869: 'write',      # 关闭参数设置界面

    # 相机相关 → 通信日志
    4884: 'writeComm', # 打开相机
    4950: 'writeComm', # 关闭相机

    # 异常/错误 → 错误日志
    4893: 'writeError', # 相机异常(已存在)
    4954: 'writeError', # 相机异常(已存在)
    5024: 'writeError', # e.what()
    5107: 'writeError', # e.what()
    5773: 'writeError', # 新增配方失败
    5960: 'writeError', # 新建NG图片文件夹失败
    6247: 'writeError', # 连接异常断开

    # 监控模式 → 操作日志
    5061: 'write',     # 关闭监控模式
    5111: 'write',     # 打开监控模式

    # 打开界面 → 操作日志
    5147: 'write',     # 打开检测参数界面
    5164: 'write',     # 打开激光参数界面
    5182: 'write',     # 打开相机参数界面
    5194: 'write',     # 打开用户界面
    5223: 'write',     # 保存方案并返回
    5237: 'write',     # 关闭参数设置界面

    # 配方管理 → 操作日志
    5561: 'write',     # 删除配方
    5703: 'write',     # 切换当前配方
    5768: 'write',     # 新增配方
    5782: 'write',     # 操作员配方
    5851: 'write',     # write
    5890: 'write',     # write
    5926: 'write',     # write

    # NG图片 → 操作日志
    5955: 'write',     # 新建NG图片文件夹成功

    # 文件 → 操作日志
    5993: 'write',     # 选择模板文件
    6018: 'write',     # 加载模板

    # 用户管理 → 操作日志
    6399: 'write',     # 添加用户
    6410: 'write',     # 删除用户
    6431: 'write',     # 修改密码

    # 打印 → 操作日志
    7572: 'write',     # 打印中
    7622: 'write',     # 关闭打印
}

# 先处理已标注的行: 把 Logger::write( 替换为 Logger::writeXxx(
for line_num, log_type in changes.items():
    idx = line_num - 1
    if idx >= len(lines):
        continue
    old = lines[idx]
    if log_type == 'write':
        # 已经是 write，不需要改
        continue
    old_func = 'Logger::write('
    new_func = f'Logger::{log_type}('
    if old_func in old:
        new = old.replace(old_func, new_func)
        if new != old:
            lines[idx] = new
            print(f'Line {line_num}: {old.strip()} -> {new.strip()}')
        else:
            print(f'Line {line_num}: SKIP (no change)')
    else:
        print(f'Line {line_num}: SKIP (not Logger::write) -> {old.strip()[:60]}')

# 额外处理: 相机相关行
# 查找 相机 关键词的行，统一改为 writeComm
for i, line in enumerate(lines):
    stripped = line.strip()
    if 'Logger::write(' in stripped:
        has_camera = False
        for kw in ['相机', '打开相机', '关闭相机',
                    '触发', '拍照', '标定', '连接']:
            if kw in stripped:
                has_camera = True
                break
        if has_camera and i+1 not in [idx-1 for idx in changes.keys()]:
            # 还没被处理过的
            pass  # 手动检查

with open(sys.argv[1], 'w', encoding='gbk') as f:
    f.writelines(lines)
print('Done')

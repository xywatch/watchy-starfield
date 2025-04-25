Import("env")
import os
import shutil

def move_firmware(source, target, env):
    # 打印详细信息
    print("=== Firmware Info ===")
    print(f"- Source files: {[str(src) for src in source]}")  # 转换为字符串列表 ['.pio/build/esp32dev/firmware.elf']
    print(f"- Target files: {[str(tgt) for tgt in target]}")  # 转换为字符串列表 ['.pio/build/esp32dev/firmware.bin']
    print(f"- Current working directory: {os.getcwd()}") # /Users/life/Documents/Arduino/go-watch-esp32-platformio
    print(f"- Build directory: {env['BUILD_DIR']}")
    print(f"- Project directory: {env['PROJECT_DIR']}")

    # 确保bin目录存在
    if not os.path.exists("bin"):
        os.makedirs("bin")
        
    # 获取固件文件路径
    firmware_path = str(target[0])
    print("firmware_path", firmware_path) # .pio\build\esp32dev\firmware.bin
    
    # 提取esp32dev部分
    path_parts = firmware_path.split(os.sep)
    board_type = path_parts[2]  # 获取路径中的第三部分，即'esp32dev'
    print("Board type:", board_type)
    
    # 构建目标路径
    dest_path = os.path.join("bin", board_type + "_firmware.bin")
    # 复制文件
    shutil.copy2(firmware_path, dest_path)
    print("Firmware copied to", dest_path)

# 注册回调
env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", move_firmware)

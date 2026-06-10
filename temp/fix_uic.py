# -*- coding: utf-8 -*-
"""Safe UI fixes - only text-level changes that preserve XML validity, then verify."""
import os
import re
import subprocess

BASE = r'D:\DM\LibreCAD-2.4(YitiJi)\librecad\src\OCRdemo'
UIC = r'D:/software/qt/5.15.2/msvc2019_64/bin/uic.exe'

def verify_all():
    """Check all .ui files pass uic"""
    all_ok = True
    for f in os.listdir(BASE):
        if not f.endswith('.ui'):
            continue
        path = os.path.join(BASE, f)
        r = subprocess.run([UIC, path], capture_output=True, timeout=10)
        if r.returncode != 0:
            err = r.stderr.decode('gbk', errors='replace')[:200]
            print(f"  FAIL: {f} - {err}")
            all_ok = False
    if all_ok:
        print("  All .ui files pass uic!")
    return all_ok

def safe_rewrite_ui(path, content):
    """Write file and verify it passes uic"""
    open(path, 'wb').write(content)
    r = subprocess.run([UIC, path], capture_output=True, timeout=10)
    if r.returncode != 0:
        err = r.stderr.decode('gbk', errors='replace')[:200]
        print(f"  FAIL after write: {os.path.basename(path)} - {err}")
        return False
    return True

def fix_fonts_bg():
    """Unify font name and ensure background color - simple text replacements"""
    for f in sorted(os.listdir(BASE)):
        if not f.endswith('.ui'):
            continue
        path = os.path.join(BASE, f)
        xml = open(path, 'rb').read()
        orig = xml

        # 1. Unify font: 微软雅黑 -> Microsoft YaHei
        xml = xml.replace(b'\xe5\xbe\xae\xe8\xbd\xaf\xe9\x9b\x85\xe9\xbb\x91', b'Microsoft YaHei')

        # 2. Ensure background color exists
        if b'rgb(220, 235, 240)' not in xml:
            # Check if there's a styleSheet on the root widget
            pat = rb'(<widget[^>]*>\s*<property name="[^>]*">.*?</property>\s*)<property name="styleSheet">'
            m = re.search(pat, xml, re.DOTALL)
            if m:
                # Replace existing styleSheet
                old = m.group(1)
                new = m.group(1)
                xml = xml.replace(old, new + b'\n  <property name="styleSheet">\n   <string notr="true">background-color:rgb(220, 235, 240);</string>\n  </property>', 1)
            else:
                # No stylesheet yet, add after windowTitle
                title_pat = rb'(<property name="windowTitle">.*?</property>)'
                m = re.search(title_pat, xml)
                if m:
                    old = m.group(0)
                    new = m.group(0) + b'\n  <property name="styleSheet">\n   <string notr="true">background-color:rgb(220, 235, 240);</string>\n  </property>'
                    xml = xml.replace(old, new, 1)

        if xml != orig:
            if safe_rewrite_ui(path, xml):
                print(f"  {f}: font+bg updated")
            else:
                print(f"  {f}: SKIPPED (would break uic)")
                open(path, 'wb').write(orig)  # revert
        else:
            print(f"  {f}: unchanged")

if __name__ == '__main__':
    # First check current state
    print("=== Verifying current .ui files ===")
    verify_all()

    print("\n=== Applying font and bg fixes ===")
    fix_fonts_bg()

    print("\n=== Final verification ===")
    verify_all()

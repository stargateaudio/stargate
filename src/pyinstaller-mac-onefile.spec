# -*- mode: python ; coding: utf-8 -*-
import os

block_cipher = None


a = Analysis(['scripts/stargate'],
             pathex=[os.path.dirname(SPECPATH)],
             binaries=[
                 ('engine/stargate-engine', 'engine'),
                 ('engine/*.dylib', 'engine'),
                 ('vendor/sbsms/cli/sbsms', 'engine'),
             ],
             datas=[
                 ('meta.json', '.'),
                 ('COMMIT', '.'),
                 ('files/', 'files'),
             ],
             hiddenimports=[
                 'sglib',
                 'sgui',
                 'logging',
             ],
             hookspath=[],
             hooksconfig={},
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)

exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          [],
          name='stargate',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          upx_exclude=[],
          runtime_tmpdir=None,
          console=False,
          disable_windowed_traceback=False,
          target_arch=None,
          codesign_identity=None,
          entitlements_file=None )
app = BUNDLE(exe,
             name='stargate.app',
             icon='macos/stargate.icns',
             bundle_identifier=None)

Make a python script translatable
--
1. add following codes to the top
```python
# This Python file uses the following encoding: utf-8
# -*- coding: utf-8 -*-
from common.i18n import events
_ = events()
``` 
2. wrap ```_()``` function around the string.

3. generate pot file (template file)
```bash
# e.g. xgettext -d base -o /data/openpilot/selfdrive/assets/locales/events.pot /data/openpilot/selfdrive/controls/lib/events.py
xgettext -d base -o <openpilot_path>/selfdrive/assets/locales/<template_file>.pot <file_to_translate>.py
```

4. add po file to languages
```bash
# e.g. cp /data/openpilot/selfdrive/assets/locales/events.pot /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events.po
cp <openpilot_path>/selfdrive/assets/locales/<template_file>.pot <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<template_file>.po
```

5. translate po file with your favorite editor.

6. generate mo file.
```bash
# e.g. msgfmt -o /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events.mo /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events
msgfmt -o <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<template_file>.mo <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<template_file>
```

Update translations
---
1. add ```_()``` around the new strings

2. generate pot file again (template file)
```bash
# e.g. xgettext -d base -o /data/openpilot/selfdrive/assets/locales/events.pot /data/openpilot/selfdrive/controls/lib/events.py
xgettext -d base -o <openpilot_path>/selfdrive/assets/locales/<template_file>.pot <file_to_translate>.py
```

3. update already translated file (merge)
```bash
# e.g. msgmerge --update /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events.po /data/openpilot/selfdrive/assets/locales/events.pot
msgmerge --update <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<file_to_translate>.po <openpilot_path>/selfdrive/assets/locales/<template_file>.pot
```

4. generate mo file again.
```bash
# e.g. msgfmt -o /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events.mo /data/openpilot/selfdrive/assets/locales/zh-TW/LC_MESSAGES/events
msgfmt -o <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<template_file>.mo <openpilot_path>/selfdrive/assets/locales/<language>/LC_MESSAGES/<template_file>
```

Reference
---
https://simpleit.rocks/python/how-to-translate-a-python-project-with-gettext-the-easy-way/
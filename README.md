# <center>hexan</center>
# ARCHIVED ([cexan](https://github.com/VorPijakov23/cexan))

## Описание

hexan (HEX ANalyzer) - Простой hex дампер написанный на C++. Был создан потому что автора не устраивала работа утилиты hexdump, а в частности little-enidian по умолчанию, и отсутствие кодирования байтов в ASCII.

## Примеры использования
#### Сценарий 1
Представим что вам захотелось посмотреть что из себя представляет файл hw.txt. Флаг --bytes, или же -b, означает количество байт в одной строке.
```bash
hexan --bytes 12 ./hw.txt
```
Output:
```
00000000    48 65 6C 6C  6F 20 57 6F  72 6C 64 21   Hello World!
```
hexan вывел номер строки, байты файла в виде hex, а так же попытался закодировать их в ASCII. Как мы видим, файл hw.txt содержит в себе текст "Hello World!"
#### Сценарий 2
Теперь задача немного по сложнее. Теперь представь, что твой друг Тихон скинул файл с подписью "Я нём чтото спрятал, и ты никогда не узнаешь что это". В порыве доказать ему что не пальцем деланный, ты начинаете думать, чтоже Тихон мог придумать? Учитывая что в школе ты учился на 5-ки, а мама вчера сказала что ты хакер и програмист, ~~когда зарегистрировал её в однокласниках~~,ты сразу же вспоминаешь о прекрастной утилите - hexan.
```bash
hexan ./image_from_tikhon.jpg
```
Output:
```
...
00001998    56 73 65 20  6D 6F 69 20  70 61 72 6F  6C 69 3A 0A  67 69 74 68  75 62 2E 63   Vse moi paroli:.github.c
000019B0    6F 6D 20 2D  20 5E 78 4C  33 37 38 39  53 5A 51 53  4E 0A 0A 0A  76 6B 2E 72   om - ^xL3789SZQSN...vk.r
000019C8    75 20 2D 20  6F 32 6C 36  7D 4B 30 3F  2D 66 3E                                u - o2l6}K0?-f>
...
```
Как мы видим в поле ASCII символов Тихон решил записать все свои пароли(А именно от github.com и vk.ru) в конец изображения. Теперь вы решаете, будет ли он вам писать, или нет, конечно если у него не включена двухфакторная аунтефикация.

Но всё ещё остаётся один вопрос. Как же Тихон смог записать данные в конец .jpg файла. Оказывается у всех людей со странными именами есть машина времени. Он просто отправился в будущее и заполучил hexan V5.0.0, с редактированием hex кода. А ты пока что подожди, когда автор допишет её.

## Установка и использование

### Установка

#### Windows
Перейдите на вкладку [Releases](https://github.com/VorPijakov23/hexan/releases/) и скачайте hexan.exe

#### Unix like system
Для установки необходим компилятор:
- gcc(g++)
- cmake
- make

Перед запуском нужно убедиться что компилятор gcc(g++) установлен
```bash
./scripts/setup.sh --clean
```
###### Опционально - если файл не запускается попробуйте сделать его исполняемым
```bash
chmod +x ./scripts/setup.sh
```

### Использование

Эта часть больше для пользователей Windows, ~~привыкших нажимать на кнопочки в GUI интерфейсе~~

###### Запуск программы на Windows:
```bash
hexan.exe [OPTIONS] [FILE]
```

## TODO

1) Сделать потдержку big endian/little endian
2) Переделать hexan в полноценный hex редактор
3) Добавить встроенный переводчик текста в hex


## Тип лицензии

Этот проект распространяется под лицензией [GPL](LICENSE).

# nikon_rc
PIC16F648A を使用した, Nikon 赤外線リモートコントローラ

### 書き込み方法
[RCDライタ](http://feng3.nobody.jp/rcd/ "RCDライタ")を接続し, picprog にて書き込みを行う.  
``picprog --erase --burn --input [HEXファイル] -d pic16f648a -p /dev/ttyUSB[0-9]``

#### パルス波について
下記のデータを使用させていただきました.  
``http://www.sbprojects.com/projects/nikon/index.php``

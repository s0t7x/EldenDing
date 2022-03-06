<h1 align="center">
  <img style="height: 128px; width: auto" src="https://github.com/s0t7x/EldenDing/blob/master/icon.ico?raw=true" /><br/>
  「EldenRing v1.02」PC版のアイテムスポナー
</h1>
<h3 align="center">EldenDing - EldenRing Item Spawner</h3>

<div align="center" style="width:80%">
<img src="https://github.com/s0t7x/EldenDing/blob/master/eldenDingDemo.gif?raw=true" />
</div>
An example of arbitrary code excecution in remote processes. Example spaws items inside EldenRing. Created solely for teaching purposes.

リモートプロセスでの任意のコード実行の例。例では、EldenRing内にアイテムを生成します。教育目的でのみ作成されました

<pre>
0x48, 0x83, 0xEC, 0x48,
0x48, 0x8B, 0x0D, 0x05, 
0x1D, 0xC6, 0x03, 0x45,
0x31, 0xC9, 0x45, 0x8D, 
0x41, 0x01, 0x48, 0x8D,
0x15, 0x0A, 0x00, 0x00,
0x00, 0xE8, 0x72, 0x8C, 
0x55, 0x00, 0x48, 0x83, 
0xC4, 0x48, 0xC3
</pre>

「MapItemManager」へのポインタ、「ItemData」形式の関数パラメータ、および「ItemDrop」の関数アドレスをASMコードに動的に提供する必要があります

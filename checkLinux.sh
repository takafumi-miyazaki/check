#!/bin/bash
 
# Linuxの資源について調査するbashスクリプト
# 調査結果を./configLinux.txtに出力する
# 参考: https://yunabe.jp/docs/maximum_number_of_threads.html

# 出力ファイル名の定義
output="./configLinux.txt"
# 出力ファイルの生成
touch $output

# uname -aをファイルに出力
echo "[uname -aの出力結果]" >> $output
uname -a >> $output
echo "" >> $output

# cat /proc/versionをファイルに出力
echo "[cat /proc/versionの出力結果]" >> $output
cat /proc/version >> $output
echo "" >> $output



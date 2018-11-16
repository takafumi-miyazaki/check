#!/bin/bash
 
# Linuxの資源について調査するbashスクリプト
# 調査結果を./configHW.txtに出力する
# 参考: https://yunabe.jp/docs/maximum_number_of_threads.html

# 出力ファイル名の定義
output="./configHW.txt"
# 出力ファイルの生成
touch $output

# lshwをファイルに出力
echo "[lshwの出力結果]" >> $output
lshw >> $output
echo "" >> $output

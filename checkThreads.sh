#!/bin/bash
 
# Linuxの資源について調査するbashスクリプト
# 調査結果を./outputThreads.txtに出力する
# 参考: https://yunabe.jp/docs/maximum_number_of_threads.html

# 出力ファイル名の定義
output="./configThreads.txt"
# 出力ファイルの生成
touch $output

# 資源の制約についてすべて調査し、ファイルに出力
# 特に並列プログラミグをする際にはプロセス数について要注意
# プロセス数制限を設定するためには/etc/secutiry/limits.confを変更する必要あり
echo "[ulimit -aの出力結果]" > $output
ulimit -a >> $output
echo "" >> $output

# システム全体のスレッド数上限をファイルに出力
# 上限値を設定するためには/etc/sysctl.confを変更する必要あり
echo "[cat /proc/sys/kernel/threads-maxの出力結果]" >> $output
cat /proc/sys/kernel/threads-max >> $output
echo "" >> $output

# メモリマップ制約をファイルに出力
# 上限値を設定するためには/etc/sysctl.confを変更する必要あり
echo "[cat /proc/sys/vm/max_map_countの出力結果]" >> $output
cat /proc/sys/vm/max_map_count >> $output
echo "" >> $output

# プロセス番号の最大値をファイルに出力
echo "[cat /proc/sys/kernel/pid_maxの出力結果]" >> $output
cat /proc/sys/kernel/pid_max >> $output
echo "" >> $output

# cpuinfoをファイルに出力
echo "[cat /proc/cpuinfoの出力結果]" >> $output
cat /proc/cpuinfo >> $output
echo "" >> $output

# meminfoをファイルに出力
echo "[cat /proc/meminfoの出力結果]" >> $output
cat /proc/meminfo >> $output
echo "" >> $output



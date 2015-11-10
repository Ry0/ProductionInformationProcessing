reset
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set xrange[-5:5]
set yrange[-5:5]
set zrange[-5:5]
set view equal xyz
set ticslevel 0
splot 'x.dat' using 1:2:3 with lines lt 1 lc rgb '#FF3D46' lw 3 title 'X axis',\
'y.dat' using 1:2:3 with lines  lt 1 lc rgb '#3DC41F' lw 3 title 'Y axis',\
'z.dat' using 1:2:3 with lines  lt 1 lc rgb '#1D5FFF' lw 3 title 'Z axis'

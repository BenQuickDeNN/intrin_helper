CC="g++"
SRC_DIR="src/"
BIN_DIR="bin/"
INC_DIR="../"
OPT="-O3 -fopenmp"

srctype=".cpp"

src_1="arrayadd"
src_2="arrayadd_performance"

rm -f $BIN_DIR/$src_1
rm -f $BIN_DIR/$src_2

$CC -g $SRC_DIR/$src_1$srctype -o $BIN_DIR/$src_1 -I $INC_DIR $OPT
$CC -g $SRC_DIR/$src_2$srctype -o $BIN_DIR/$src_2 -I $INC_DIR $OPT
#!/bin/bash

BASE=$(cat failed-expr.txt 2>/dev/null | head -n1)
BASE_LEN=$(echo -n "$BASE" | wc -c)
EXPR_LEN=$(cat failed-expr.txt 2>/dev/null | tail -n1 | wc -c)
RESULT_BC=$((echo -n "obase=${BASE_LEN};ibase=${BASE_LEN};"; cat failed-expr.txt 2>/dev/null | tail -n1; echo) | BC_LINE_LENGTH=0 bc -q)
echo "bc: $RESULT_BC"
RESULT=$(cat failed-expr.txt 2>/dev/null | tail -n1 | valgrind ../calc "$BASE" "()+-*/%" "$EXPR_LEN")
echo "bistro: $RESULT"
colordiff <(echo "$RESULT_BC") <(echo "$RESULT")
exit $?

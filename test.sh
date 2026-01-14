#!/bin/bash

# ألوان
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
RESET='\033[0m'

# دالة لتوليد الأرقام واختبارها
test_push_swap() {
    local count=$1
    local limit=$2
    echo -e "${YELLOW}--- Testing $count Numbers (Limit: $limit) ---${RESET}"
    
    # توليد أرقام عشوائية فريدة باستخدام بايثون
    ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-2000, 2000), $count))))")
    
    # تشغيل البرنامج
    MOVES=$(./push_swap $ARG)
    RESULT=$(echo "$MOVES" | ./checker_linux $ARG)
    COUNT_MOVES=$(echo "$MOVES" | wc -l)
    
    if [ "$RESULT" == "OK" ]; then
        if [ "$COUNT_MOVES" -le "$limit" ]; then
            echo -e "Result: ${GREEN}OK${RESET} | Moves: ${GREEN}$COUNT_MOVES${RESET}"
        else
            echo -e "Result: ${GREEN}OK${RESET} | Moves: ${RED}$COUNT_MOVES (Too many!)${RESET}"
        fi
    else
        echo -e "Result: ${RED}KO${RESET} | Numbers: [ $ARG ]"
    fi
    echo ""
}

# التأكد من وجود الملفات
if [ ! -f "./push_swap" ] || [ ! -f "./checker_linux" ]; then
    echo "Error: push_swap or checker_linux not found!"
    exit 1
fi

chmod +x checker_linux

# تشغيل الاختبارات
test_push_swap 3 3
test_push_swap 4 12
test_push_swap 5 12
test_push_swap 100 700
test_push_swap 500 5500
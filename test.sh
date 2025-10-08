#!/bin/bash

# Push-swap Testing Script
# Generates random numbers, tests the algorithm, and saves results

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default values
NUM_COUNT=10
RANGE=100

# Parse arguments
if [ "$1" ]; then
    NUM_COUNT=$1
fi

if [ "$2" ]; then
    RANGE=$2
fi

# Auto-detect checker based on OS
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    CHECKER="./checker_Mac"
else
    # Linux
    CHECKER="./checker_linux"
fi

# Check if checker exists
if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}⚠️  Warning: Checker not found at ${CHECKER}${NC}"
    echo -e "${YELLOW}Continuing without validation...${NC}"
    CHECKER=""
fi

# Generate random numbers
# Use gshuf on macOS (brew install coreutils) or fallback to a different method
if command -v shuf &> /dev/null; then
    ARG=$(shuf -i 1-${RANGE} -n ${NUM_COUNT} | tr '\n' ' ')
elif command -v gshuf &> /dev/null; then
    ARG=$(gshuf -i 1-${RANGE} -n ${NUM_COUNT} | tr '\n' ' ')
else
    # Fallback for macOS: generate unique numbers using seq, sort, and head
    ARG=$(seq 1 ${RANGE} | sort -R | head -n ${NUM_COUNT} | tr '\n' ' ')
fi

# Create output directory if it doesn't exist
mkdir -p operations-output

TIMESTAMP=$(date +%Y%m%d_%H%M%S)
OUTFILE="operations-output/test_${NUM_COUNT}nums_${TIMESTAMP}.txt"

echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}🧪 Push-Swap Test${NC}"
echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "📊 Testing with: ${YELLOW}${NUM_COUNT}${NC} numbers (range: 1-${RANGE})"
echo -e "🔢 Numbers: ${ARG}"
echo ""

# Run push_swap and save operations
./push_swap $ARG > "$OUTFILE"

# Count operations
OPS_COUNT=$(wc -l < "$OUTFILE")

# Check if sorted correctly (only if checker is available)
if [ -n "$CHECKER" ]; then
    RESULT=$(./push_swap $ARG | $CHECKER $ARG 2>/dev/null)
else
    RESULT="SKIPPED (no checker)"
fi

# Display results
echo -e "📁 Saved to: ${BLUE}${OUTFILE}${NC}"
echo -e "⚙️  Operations used: ${YELLOW}${OPS_COUNT}${NC}"
echo -e "🖥️  Using checker: ${BLUE}${CHECKER:-none}${NC}"

if [ "$RESULT" = "OK" ]; then
    echo -e "✅ Result: ${GREEN}${RESULT}${NC} - Correctly sorted!"
elif [ "$RESULT" = "KO" ]; then
    echo -e "❌ Result: ${RED}${RESULT}${NC} - Something went wrong!"
else
    echo -e "⚠️  Result: ${YELLOW}${RESULT}${NC}"
fi

# Performance reference (42 school requirements)
echo ""
echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}📈 Performance Reference (42 School):${NC}"
if [ ${NUM_COUNT} -eq 3 ]; then
    echo "  • 3 numbers: max 3 operations (you used: ${OPS_COUNT})"
elif [ ${NUM_COUNT} -eq 5 ]; then
    echo "  • 5 numbers: max 12 operations (you used: ${OPS_COUNT})"
elif [ ${NUM_COUNT} -eq 100 ]; then
    echo "  • 100 numbers:"
    echo "    - 5 points: < 700 operations"
    echo "    - 4 points: < 900 operations"
    echo "    - 3 points: < 1100 operations"
    echo "    - 2 points: < 1300 operations"
    echo "    - 1 point:  < 1500 operations"
    echo "    📊 You used: ${OPS_COUNT}"
elif [ ${NUM_COUNT} -eq 500 ]; then
    echo "  • 500 numbers:"
    echo "    - 5 points: < 5500 operations"
    echo "    - 4 points: < 7000 operations"
    echo "    - 3 points: < 8500 operations"
    echo "    - 2 points: < 10000 operations"
    echo "    - 1 point:  < 11500 operations"
    echo "    📊 You used: ${OPS_COUNT}"
fi
echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo ""

#!/bin/bash
# install-hook.sh — Install the post-commit hook for auto stats + push
#
# Usage: bash scripts/install-hook.sh
# Run once from the repo root after cloning.

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
HOOK_SRC="$REPO_ROOT/.githooks/post-commit"
HOOK_DST="$REPO_ROOT/.git/hooks/post-commit"

if [ ! -f "$HOOK_SRC" ]; then
    echo "ERROR: Hook source not found: $HOOK_SRC"
    echo "   Make sure you're in the repo root."
    exit 1
fi

cp "$HOOK_SRC" "$HOOK_DST"
chmod +x "$HOOK_DST"

echo "Post-commit hook installed: $HOOK_DST"
echo ""
echo "What happens after every commit:"
echo "   1. Scans repo for new .cpp solution files"
echo "   2. Updates all README stats (badges, totals, chart)"
echo "   3. Amends the README change into your commit"
echo "   4. Pushes to origin"
echo ""
echo "You can also run the updater manually:"
echo "   python3 scripts/update_stats.py"

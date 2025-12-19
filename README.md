# LeetCode Solutions

A structured repository for storing the solutions to Data Structures and Algorithms problem from popular coding sheets like Striver, NeetCode, Blind 75, and more.

## Repository Structure

```
leetcode/
├── sheets/
│   ├── blind_75/              # Blind 75 curated problems
│   │   ├── arrays/
│   │   ├── binary_search_tree/
│   │   ├── binary_tree/
│   │   ├── linked_list/
│   │   ├── queue/
│   │   ├── sliding_window/
│   │   ├── stack/
│   │   └── two_pointers/
│   └── neetcode_150/          # NeetCode 150 problems
├── lc                         # Problem file creator script
└── README.md                  # Project documentation
```

## File Naming Convention

All problem solutions follow a standardized naming convention:

```
XXX_problem_name.cpp
```

Where:

- `XXX` is the zero-padded problem number (e.g., `001`, `042`, `1337`)
- `problem_name` is the lowercase, underscore-separated problem title
- Extension can be `.cpp`, `.py`, `.java`, etc.

**Examples:**

- `001_two_sum.cpp`
- `042_trapping_rain_water.py`
- `1372_longest_zigzag_path_in_a_binary_tree.cpp`

## Quick Start

### Prerequisites

- Python 3.7+
- `requests` library (automatically installed in the project's virtual environment)

### Using the `lc` Command

The `lc` (LeetCode) command is a convenient tool to create properly named problem files from any directory.

#### Basic Usage

```bash
# Create a file in the current directory
lc https://leetcode.com/problems/two-sum/

# Specify a different directory
lc https://leetcode.com/problems/two-sum/ sheets/blind_75/arrays

# Use a different file extension (default: cpp)
lc https://leetcode.com/problems/two-sum/ . py

# Create in a relative path
lc https://leetcode.com/problems/two-sum/ ../arrays
```

#### Command Syntax

```bash
lc <leetcode_url> [directory] [extension]
```

**Parameters:**

- `leetcode_url` (required): Full LeetCode problem URL
- `directory` (optional): Target directory (default: current directory `.`)
- `extension` (optional): File extension (default: `cpp`)

#### What It Does

1. **Fetches problem metadata** from LeetCode's API (problem number, title)
2. **Generates properly formatted filename** following the `XXX_problem_name.ext` convention
3. **Creates the file** with a starter template in the current directrory including:
   - Problem number and title
   - Problem URL
   - Placeholders for difficulty and topics

#### Example Output

Running:

```bash
lc https://leetcode.com/problems/two-sum/
```

Creates `0XX_two_sum.cpp` with:

```cpp
/*
 * Problem: 1. Two Sum
 * URL: https://leetcode.com/problems/two-sum/
 * Difficulty:
 * Topics:
 */

```

## Workflow

1. **Navigate** to your target directory:

   ```bash
   cd sheets/blind_75/arrays
   ```

2. **Create a problem file**:

   ```bash
   lc https://leetcode.com/problems/three-sum/
   ```

3. **Start coding** your solution in the generated file

4. **Commit** your solution:
   ```bash
   git add .
   git commit -m "Add: Three Sum solution"
   ```

## Tips

- The `lc` command works from **any directory** in your system
- Use relative paths (`.`, `..`) for flexible file placement
- The script automatically handles duplicate files with a confirmation prompt
- Problem metadata is fetched in real-time, ensuring accuracy

## License

See [LICENSE](LICENSE) file for details.

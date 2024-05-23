#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * @brief Given a vector of strings @c strings, reduce this vector so that each
 * string appears only once. After the function call, @c strings contains the
 * same set of elements (possibly sorted) as the original vector, but each
 * element appears only once.
 *
 * @param strings The given vector of strings.
 */
void dropDuplicates(std::vector<std::string> &strings) {
  // DONE: Implement this function.
  std::sort(strings.begin(), strings.end());
  auto uniqueEnd = std::unique(strings.begin(), strings.end());
  strings.erase(uniqueEnd, strings.end());
}

/**
 * @brief Given a vector of strings @c strings and a nonnegative integer @c k,
 * partition the vector into two parts (with the elements rearranged) so that
 * the first part contains all the strings with length no greater than @c k and
 * the second part contains the rest of the strings. Return an iterator just
 * past the last element of the first part.
 *
 * @param strings The given vector of strings.
 * @return An iterator just past the last element of the first part. In
 * particular, if the second part is not empty, the returned iterator will refer
 * to the first element of the second part.
 */
auto partitionByLength(std::vector<std::string> &strings, std::size_t k) {
  return std::partition(strings.begin(), strings.end(),
                 [k](const std::string &str)
                 { return str.length() <= k; });
}

/**
 * @brief Generate all the permutations of {1, 2, ..., n} in lexicographical
 * order, and print them to @c os.
 *
 */
void generatePermutations(int n, std::ostream &os) {

  std::vector<int> numbers(n);

  // DONE: Fill `numbers` with {1, 2, ..., n}.
  std::iota(numbers.begin(), numbers.end(), 1);

  do {
    // DONE: Print the numbers, separated by a space.
    std::for_each(numbers.begin(), numbers.end(),
                  [&os](int num)
                  { os << num << ' '; });
    os << '\n';
  } while (std::next_permutation(numbers.begin(), numbers.end()));
}

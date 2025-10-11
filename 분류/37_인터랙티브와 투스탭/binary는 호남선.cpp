#include <iostream>

// Helper function to ask a query and get the result.
int query(int k)
{
    std::cout << "? " << k << std::endl;
    int response;
    std::cin >> response;
    return response;
}

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // The difference between the count of "01" and "10" pairs is
    // equivalent to the last element minus the first element of the sequence.
    // s_N - s_1 = sum_{i=1}^{N-1} (s_{i+1} - s_i) = count("01") - count("10")

    // Query for the first element.
    int first_bit = query(1);

    // Query for the last element.
    int last_bit = query(N);

    // Calculate the difference and print the final answer.
    int result = last_bit - first_bit;
    std::cout << "! " << result << std::endl;

    return 0;
}

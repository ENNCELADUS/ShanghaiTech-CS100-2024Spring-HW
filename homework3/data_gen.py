import sys
import random
import string

def generate_random_string(max_length):
    string_length = random.randint(1, max_length)

    # Define the characters that will be used to generate the random string
    characters = string.ascii_letters + string.digits
    # Generate the random string
    return ''.join(random.choices(characters,  k = string_length))

def generate_palindrome(max_length):
    half_length = random.randint(1, max_length // 2)

    # Define the characters that will be used to generate the random string
    characters = string.ascii_letters + string.digits
    
    # Generate the first half part of the palindrome
    half = ''.join(random.choices(characters, k = half_length))
    
    if max_length % 2 == 0:
        # If the palindrome's length is even number
        return half + half[::-1]
    else:
        # Odd number length
        return half + random.choice(characters) + half[::-1]

n = int(sys.argv[1])
max_length = int(sys.argv[2])

print(n)
for _ in range(n):
    if random.choice([True, False]):
        palindrome = generate_palindrome(max_length)
        print(len(palindrome))
        print(palindrome)
    else:
        random_string = generate_random_string(max_length)
        print(len(random_string))
        print(random_string)
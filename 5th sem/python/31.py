def count_words_in_file(filename):
    try:
        with open(filename, 'r') as file:
            content = file.read()
            words = content.split()
            return len(words)
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return -1

# Provide the filename as input
filename = "content.txt"

# Call the function to count words
word_count = count_words_in_file(filename)

if word_count != -1:
    print(f"The number of words in '{filename}' is: {word_count}")

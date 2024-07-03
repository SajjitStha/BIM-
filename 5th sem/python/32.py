def filter_keywords(input_file, output_file):
    try:
        with open(input_file, 'r') as infile:
            keywords = infile.readlines()
        
        filtered_keywords = [keyword.strip() for keyword in keywords if len(keyword.strip()) > 3]
        
        with open(output_file, 'w') as outfile:
            for keyword in filtered_keywords:
                outfile.write(keyword + '\n')
                
        print(f"Filtered keywords written to {output_file}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Specify the file names and the length threshold
input_file = "content.txt"
output_file = "output.txt"


# Call the function to filter keywords
filter_keywords(input_file, output_file)
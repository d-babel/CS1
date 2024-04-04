# return sum of count num of total chars
def count_letters(text):
    return sum(c.isalpha() for c in text)

# return length of split by word sentences
def count_words(text):
    return len(text.split())

# count num of sentences by punctuation
def count_sentences(text):
    #occurrences of end of sentence punctuation
    return sum(text.count(end) for end in ['.', '?', '!'])

# compute Coleman-Liau index
def compute_index(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    return round(0.0588 * L - 0.296 * S - 15.8)


text = input("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)
index = compute_index(letters, words, sentences)

#print grade lvl based on computed index
if index < 1:
    print("before grade 1")
elif index >= 16:
    print("grade 16+")
else:
    # f-string allows string literals "{}"
    print(f"grade {index}")

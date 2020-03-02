def spin_words(sentence):
    words, result = sentence.split(), []
    for word in words:
        result.append(word[::-1]) if len(word) > 4 else result.append(word)
    return ' '.join(result)


print(spin_words('Welcome'))

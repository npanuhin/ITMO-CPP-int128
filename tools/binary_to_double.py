number = '11100000001001110010101101011000101101111101011001011100110001001011010010100000001010101110100000111001101011100111101010111011'

number = number.replace(' ', '')
is_negative = number[0] == '1'

if is_negative:
    # number = number.replace('1', '2').replace('0', '1').replace('2', '0')
    number = '1' + number[-63:]
else:
    number = number[-64:]

print(number)

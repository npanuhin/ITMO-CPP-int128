number = '11101001101110110000000010000001101111000101100000110010110110100001000000100101111000100110101011110010110010101010001101010001'

number = number.replace(' ', '')
if number[0] == '1':
    print(
        '-' + str(int(number[1:].replace('1', '2').replace('0', '1').replace('2', '0'), 2) + 1)
    )
else:
    print(int(number, 2))

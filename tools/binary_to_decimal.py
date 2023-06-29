number = '11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110'

number = number.replace(' ', '')
if number[0] == '1':
    print(
        '-' + str(int(number[1:].replace('1', '2').replace('0', '1').replace('2', '0'), 2) + 1)
    )
else:
    print(int(number, 2))

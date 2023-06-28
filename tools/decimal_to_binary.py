number = '-29256914613596052498173063890724085253'

number = number.replace(' ', '')

if number[0] == '-':
    print(
        bin(int(number[1:]) - 1)[2:].zfill(128).replace('1', '2').replace('0', '1').replace('2', '0')
    )
else:
    print(
        bin(int(number))[2:].zfill(128)
    )

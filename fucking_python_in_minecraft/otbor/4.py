import minecraft as mine
mc = mine.Minecraft.create()

st = ''
for i in range(0, 11):
    st += str(10 - i) + ' '
print(st)
mc.setSign(200, 35, 150, 68, 8, 'Hello', 'Minecraft world!', st, 'Kapusta') 
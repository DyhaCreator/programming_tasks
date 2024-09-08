import minecraft as mine
mc = mine.Minecraft.create()

for i in range(0, 5):
    if (5 - i == 0):
        mc.postToChat('Teleport!')
        mc.player.setTilePos(100, 50, 100)
    else:
        mc.postToChat(str(5 - i))
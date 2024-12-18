import minecraft as mine
mc = mine.Minecraft.create()


pos = mc.player.getTilePos()
for i in range(10):
    mc.spawnEntity(pos.x, pos.y, pos.z, 20)
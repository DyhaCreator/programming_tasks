import minecraft as mine
mc = mine.Minecraft.create()

pos = mc.player.getTilePos()

mc.setBlocks(pos.x, pos.y, pos.z, pos.x + 10, pos.y + 10, pos.z + 10, 20)
mc.setBlocks(pos.x + 1, pos.y + 1, pos.z + 1, pos.x + 9, pos.y + 9, pos.z + 9, 0)
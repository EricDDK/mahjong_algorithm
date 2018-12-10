

local function main( ... )
	local MJLogic = require("MahjongLogic")
	local isHu = MJLogic:check_hu({1,1,2,2,2,3,3,3,4,4,4,5,5,5})
	print("the test of is hu = ",isHu)
end

main()
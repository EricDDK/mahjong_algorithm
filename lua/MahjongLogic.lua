-- 判断是否胡牌基类

-- 判断所有胡牌的逻辑在这，各自子游戏的规则去子游戏完成
--
-- 1.首先找出所有包含一对的情形，移除对子（注意去重），记下剩余牌的所有集合为Tn;
-- 2.针对每个Tn中的数组尝试移除一个顺子，成功转到2，失败到3。
-- 3.针对每个Tn中的数组尝试移除一个刻子（DDD），成功转到2。
-- 4.若当前的数组的数量变为0，则表示，当前的方案可以胡牌。
-- 去除对子后需要满足 N * ABC + M *DDD

local MJLogic = MJLogic or {}

-- 排序牌
function MJLogic:sort_card(cards)
    table.sort(cards,function ( a,b )
        return a < b
    end)
end

-- virtual
-- 寻找三个相同的的牌，也就是DDD的牌型
function MJLogic:remove_same_three( cards )
    if #cards < 3 then
        return false
    end
    for i=1,#cards - 2 do
        if cards[i] == cards[i+1] and cards[i+1] == cards[i+2] then
            table.remove( cards, i+2 )
            table.remove( cards, i+1 )
            table.remove( cards, i )
            return true
        end
    end
    return false
end

-- virtual
-- 寻找三张连续的牌，ABC类型的
-- 1-9 10-18 19-27 28-31风  32-34字  35-42花
function MJLogic:remove_straight_three(cards)
    local length = #cards
    if length < 3 then
        return false
    end
    local ij  --内层for循环的 i+j
    local ijk  --内层for循环 i+j+k
    local k = 1 --第三层for k = 1,1 do 转为外层赋值 k = 1
    for i = 1, length - 2 do
        -- 必须是万条筒才行,而且顺子的第一个必须不可以是89牌型，这无法形成顺子
        if cards[i] <= 25 and cards[i] ~= 8 and cards[i] ~= 9 and cards[i] ~= 17 and cards[i] ~= 18 then
            for j = 1, 4 do
                ij = i + j
                if ij <= length and cards[ij] == cards[i] + 1 then
                    --for k = 1, 1 do  --内循环越少越好
                    ijk = ij + k
                    if ijk <= length and cards[ijk] == cards[ij] + 1 then
                        table.remove(cards, ijk)
                        table.remove(cards, ij)
                        table.remove(cards, i)
                        return true
                    end
                --end
                end
            end
        end
    end
    return false
end

-- 检测是否是ABC DDD的牌型，是就胡，不是就不胡
function MJLogic:check_3n( cards )
    local tmpCards = clone(cards)
    while self:remove_same_three(tmpCards) do
        
    end
    while self:remove_straight_three(tmpCards) do
        
    end
    if #tmpCards == 0 then
        return true
    end

    tmpCards = clone(cards)
    while self:remove_straight_three(tmpCards) do
        
    end
    while self:remove_same_three(tmpCards) do
        
    end
    if #tmpCards == 0 then
        return true
    end
    return false
end

-- virtual 
-- 这里是判断垃圾胡的统一逻辑，在派生类中重载此函数，可以增加特定条件满足各种规则
-- 统一传统判断是否胡
function MJLogic:check_hu( valueCards )
    self:sort_card(valueCards)
    -- 有花胡不了
    if valueCards[#valueCards] >= 35 then
        return false
    end
    local cards
    for i=1,#valueCards - 1 do
        if(valueCards[i] == valueCards[i+1]) then
            cards = clone(valueCards)
            table.remove( cards, i+1 )
            table.remove( cards, i )
            if #cards == 0 or self:check_3n(cards) then
                return true
            end
        end
    end
    return false
end

function clone(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local newObject = {}
        lookup_table[object] = newObject
        for key, value in pairs(object) do
            newObject[_copy(key)] = _copy(value)
        end
        return setmetatable(newObject, getmetatable(object))
    end
    return _copy(object)
end

return MJLogic

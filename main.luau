-- Welcome to the Luau Playground!
-- Write your code here and click Run

-- CPP Bucket Sort Rewrite
local MySort = require("./MySort")

local list = {100, 100, 100, 519, 37, 9999, 3, 1, 238}

local function values()
    local s  = ""

    for _, v in list do
        local numTostring = tostring(v)
        s ..= numTostring .. " "
    end
    return s
end

print(`Original array elements \n{values()}`)
print("----------------")

MySort.Sort(list)

print("----------------")
print()
print("Array elements in unsorted order:")
print(list)

print("----------------")
print()
table.sort(list)
print(`Array elements in sorted order: {values()}`)

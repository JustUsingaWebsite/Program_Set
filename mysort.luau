-- New file
local MySort = {}
type IntArray = {number}
type BucketArray = {[number]: IntArray}
local Bucket = {} :: BucketArray
local Collectionlist = {} :: IntArray
local task = require("@lune/task")

--------------------------------------------
--------PRIVATE--------
--------------------------------------------
local function returnLargest(array: IntArray): number
  local bigNumber = 0
    for _, v in array do
      local diff = math.max(bigNumber, v)
      bigNumber = diff
    end

  return bigNumber
end

-- returns the max amount of digits a number within the array has so {555} -> 3
local function _determineMaximumDigits(array : IntArray) : number
    -- local largest_value = returnLargest(array)
    return #tostring(returnLargest(array))
end


-- create buckets based on the raisedPower
local function _distributeValues(array: {number}, raisedPower:number)
  local RaisedPowerDigit

  -- loop thru all the numbers in the array
  for _, arrayValue in array do
      -- get the Raised Power Digit eg -> raisedPower: 1 and our array[1] is 335 so we return [5] since thats the first digit
      RaisedPowerDigit = math.floor(arrayValue / math.pow(10, raisedPower - 1)) % 10 :: number

      -- Create and append to bucket
      Bucket[RaisedPowerDigit] = Bucket[RaisedPowerDigit] or {} -- Bucket [ ] is a big empty list so we create smaller lists [] and put them into bucket so Bucket [ [], [], [] ]
      -- Bucket[RaisedPowerDigit][#Bucket[RaisedPowerDigit] + 1] = arrayValue
      table.insert(Bucket[RaisedPowerDigit], arrayValue) -- Number: 335 -> bucket [5] -> [..., 335]
  end
end

local function _collectValues(array: IntArray)

    -- clear the table before so since we get a new list of numbers
    table.clear(Collectionlist)
    table.clear(array)

    -- loop thru each bucket and collect
    for _, v in pairs(Bucket) do
        for _, v2 in v do
            table.insert(Collectionlist, v2);
        end
    end

    for i, value in Collectionlist do
        array[i] = value
    end
    --lastly return the array as our new list for the next bucket creation
    return Collectionlist
end

local function _resetBucket()
    return table.clear(Bucket)
end

local function _cleanup()
    _resetBucket()
    table.clear(Collectionlist)
end

local function _printBucket()
    return print(Bucket)
end

--------------------------------------------
--------PUBLIC--------
--------------------------------------------

function MySort.Sort(array: IntArray)

    -- get the N amount of digits eg-> 55 has 2 digits
    local totalDigits = _determineMaximumDigits(array)
    _resetBucket()

    -- start looping thru the list of numbers eg-> {255, 8, 25}
    for i=1, totalDigits do
        _distributeValues(array, i)
        _collectValues(array)
        _printBucket()

        if i == totalDigits then continue end
        task.spawn(_cleanup)
        -- if you do not have lune runtime then just _cleanup() with coroutines -> coroutine.resume(coroutine.create(_cleanup))
    end
end

return MySort

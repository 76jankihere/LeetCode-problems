/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left = 0;
    let right = height.length - 1;
    let maxWater = 0;

    while (left < right) {
        // Calculate width
        let width = right - left;
        
        // Find the height of the container (limited by the shorter line)
        let currentHeight = Math.min(height[left], height[right]);
        
        // Update maxWater if current area is larger
        let currentArea = width * currentHeight;
        maxWater = Math.max(maxWater, currentArea);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
};

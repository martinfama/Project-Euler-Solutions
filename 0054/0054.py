from pokerkit import StandardHighHand

with open("0054_poker.txt", "r"):
    lines = [
        line.strip().replace(" ", "")
        for line in open("0054_poker.txt", "r").readlines()
    ]
    hands = [[line[:10], line[10:]] for line in lines]
    # undercase every other character for each hand
    for i in range(len(hands)):
        hands[i][0] = "".join(
            [
                hands[i][0][j].lower() if j % 2 == 1 else hands[i][0][j]
                for j in range(10)
            ]
        )
        hands[i][1] = "".join(
            [
                hands[i][1][j].lower() if j % 2 == 1 else hands[i][1][j]
                for j in range(10)
            ]
        )

p1_wins = 0
for hand in hands:
    p1 = StandardHighHand(hand[0])
    p2 = StandardHighHand(hand[1])
    if p1 > p2:
        p1_wins += 1

print(f"Player 1 wins {p1_wins} out of {len(hands)} hands.")

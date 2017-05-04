#!/usr/bin/env ruby
# ***************************************************************************** #
#                                                                               #
#                                                          :::      ::::::::    #
#    filler_trainer.rb [ version 1.1 ]                   :+:      :+:    :+:    #
#                                                      +:+ +:+         +:+      #
#    By: jcatinea                                    +#+  +:+       +#+         #
#                                                  +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 14:37:26 by jcatinea           #+#    #+#              #
#    Updated: 2016/12/15 14:37:26 by jcatinea          ###   ########.fr        #
#                                                                               #
# ***************************************************************************** #

$g_maps = ["maps/map00", "maps/map01", "maps/map02"]
$g_players = ["champely.filler", "abanlin.filler", "hcao.filler", "grati.filler"]
$g_players += ["carli.filler", "superjeannot.filler"]
$g_players.map! { |player| "players/" + player}

require_relative 'filler_core.rb'

def tournament(player, silent = false)
	$g_players.each { |challenger|
		$g_maps.each { |map|
			i = 0
			score = 0
			while i < 5 do
				result = fight(map, player, challenger)
				score += 1 if result == 2
				redo if result == -42
				break if (score >= 3 || (i - score) >= 3)
				i += 1
			end
			p_name = player.partition("players/")[2].partition(".filler")[0]
			c_name = challenger.partition("players/")[2].partition(".filler")[0]
			map_name = map.partition("maps/")[2]
			if (score) >= 3
				winner = c_name
				loser = p_name
			else
				winner = p_name
				loser = c_name
				score = (i - score)
			end
			string = winner + " beated " + loser + " " + score.to_s + " to "
			string += (i - score).to_s + " on " + map_name  + "\n"
			$stdout.write(string) unless (silent)
			if (winner == c_name)
				string = "You lost the tournament"
				string += " to" + c_name + " on " + map_name + "\n" if (silent)
				$stdout.write(string)
				return (0)
			else
				puts "You won this fight, the tournament continues" unless (silent)
			end
		}
	}
	puts "You won the tournament"
	return (1)
end

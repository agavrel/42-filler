/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:28:35 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/17 15:59:14 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_MESSAGES_H
# define ERRORS_MESSAGES_H

# define MSG0	"error: Dynamic memory allocation failed.\n"
# define MSG1	"usage: ./filler_visualizer file\n"

# define MSG2	"TO DELETE\n"
# define MSG4	"TO DELETE\n"

# define MSG5	"error: XML symbols \"-->\" is missing in config file (.rt).\n"
# define MSG6	"error: XML symbols \"<!--\" is missing in config file (.rt).\n"

# define MSG7	" is missing in config file (.rt).\n"
# define MSG8	"error: Invalid character(s) or balise(s) name in file (.rt).\n"
# define MSG9	"error: Nothing found inside balises "
# define MSG10	"error: Invalid element(s) inside balises "

# define MSG11	"error: Ambient (AO) value must be set between 0. and 1.\n"
# define MSG12	"error: Anti-Aliasing (AA) value must be : 0, 2, 4, 8 or 16.\n"
# define MSG13	"error: Max-Reflexion value must be set between 0 and 10.\n"
# define MSG14	"error: Invalid value inside balises "
# define MSG15A	" is missing inside "
# define MSG15B	" balises in config file (.rt).\n"
# define MSG16	"error: Focal Lenght value must be set between 18 and 200.\n"

# define MSG17	"error: At least one camera is needed in config file (.rt).\n"
# define MSG18	"error: At least one light is needed in config file (.rt).\n"
# define MSG19	"error: At least one object is needed in config file (.rt).\n"

# define MSG20	"error: Too many cameras in config file (.rt).\n"
# define MSG21	"error: Too many lights in config file (.rt).\n"
# define MSG22	"error: Too many objects in config file (.rt).\n"

# define MSG23	"error: Opacity value must be set between 0. and 1.0.\n"

# define MSG24	"error: Tag <position> is needed for every camera.\n"
# define MSG25	"error: Tag <rotation> is needed for every camera.\n"
# define MSG26	"error: Tag <position> is needed for every light.\n"
# define MSG27	"error: Tag <position> is needed for every object.\n"

# define MSG28	"error: Tag <type> is needed for every object.\n"

# define MSG29	"error: Failed to initialize the SDL Framework.\n"
# define MSG30	"error: Failed to create the SDL window struct.\n"
# define MSG31	"error: Failed to create the SDL renderer struct.\n"
# define MSG32	"error: Failed to find or import image.\n"

# define MSG33	"error: Tag <color> isn't necessary in camera.\n"
# define MSG34	"error: Tag <visibility> isn't necessary in camera.\n"
# define MSG35	"error: <intensity> value must be set between 0.0 and 50.0.\n"
# define MSG36	"error: Invalid value in <color-rgb> inside <light>.\n"
# define MSG37	"error: Invalid value in <color-rgb> inside <object>.\n"

# define MSG38	"error: <radius> value must be set between 0.0 and 500.0.\n"
# define MSG39	"error: <width> value must be set between 0.0 and 1000.0.\n"
# define MSG40	"error: <height> value must be set between 0.0 and 1000.0.\n"

# define MSG41	"error: Tag <type> is needed for every light.\n"

# define MSG42  "error: Initialization of OpenCL failed.\n"

# define MSG43	"error: <lenght> value must be set between 0.0 and 1000.0.\n"

# define MSG44	"error: <reflection> value must be set between 0.0 and 1.0.\n"
# define MSG45	"error: <refraction_index> value not set between 1.0 and 2.8.\n"
# define MSG46	"error: <refraction_intensity> not set between 0.0 and 1.0.\n"
# define MSG47	"error: <specular> value must be set between 0.0 and 1.0.\n"

#endif

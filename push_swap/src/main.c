/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 14:21:10 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_cb	a;
	t_data	data;

	if (ac < 2)
		return (1);
	a = get_stack_a(++av);
	init_data(a, &data);
	// sort_three(&data);
	// sort_five(&data);
	sortn(&data);
	// printf("\n---------a------------\n");
	// for (int i = 0; i < data.a.size; i++)
	// {
	// 	printf("%d ", data.a.stack[i]);
	// }
	// printf("\n---------b------------\n");
	// for (int i = 0; i < data.b.size; i++)
	// {
	// 	printf("%d ", data.b.stack[i]);
	// }
}
// ARG="478 277 481 324 205 199 392 166 272 490 235 10 412 160 102 223 209 43 175 108 207 238 239 1 204 230 417 126 440 482 332 161 94 197 315 182 144 292 278 456 231 11 397 17 6 492 428 350 33 261 335 35 46 20 263 295 452 116 170 385 162 29 87 86 271 416 214 273 49 9 268 179 164 395 406 448 441 67 114 212 128 185 95 349 303 351 363 459 194 314 52 158 228 252 165 258 479 39 302 301 44 24 249 234 491 45 90 210 64 476 50 256 18 181 489 106 15 236 176 352 16 362 284 422 373 76 157 343 193 196 57 418 257 21 354 287 141 4 497 168 396 457 494 331 460 415 66 312 186 300 386 264 74 224 240 213 142 51 474 404 348 337 149 269 109 7 286 245 477 407 374 432 450 338 250 487 283 244 260 316 296 466 241 124 389 496 112 431 408 23 40 135 266 242 465 99 455 146 500 322 305 248 211 323 232 359 365 390 402 325 463 225 454 189 195 347 282 190 191 307 115 89 458 25 198 461 334 122 111 375 329 311 270 360 233 436 364 419 379 218 367 226 423 188 27 299 438 71 139 445 101 434 467 72 480 243 399 81 255 253 68 96 156 368 462 41 53 178 222 13 297 293 274 384 388 376 150 320 318 475 291 93 79 444 98 330 280 148 107 430 381 353 216 309 382 328 134 201 473 346 183 369 288 405 499 12 306 326 14 140 229 453 70 75 254 403 58 317 237 65 121 356 411 32 344 485 82 100 42 200 464 220 192 219 289 85 73 19 2 336 221 151 59 91 387 433 413 184 251 5 443 83 130 247 34 486 54 84 439 357 153 279 31 380 3 152 118 143 410 117 55 63 488 371 180 78 435 304 333 447 77 56 174 262 391 483 48 424 400 113 451 276 62 339 393 104 159 426 30 484 470 155 208 394 358 429 265 290 294 215 217 138 154 187 61 469 498 275 421 285 60 97 345 310 136 327 92 420 110 398 80 177 125 147 172 472 202 298 414 173 366 103 401 427 340 308 409 88 383 163 26 47 167 442 341 372 321 468 123 69 361 259 319 8 131 120 471 493 133 145 129 137 378 38 281 446 28 132 355 377 119 171 437 246 227 495 267 36 203 206 425 370 169 127 37 313 22 105 342 449 "; ./push_swap $ARG | ./checker_linux $ARG

// ARG="3186 473 495 398 336 183 108 145 70 489 103 276 479 447 436 102 377 216 452 338 382 454 362 346 458 75 297 124 94 45 466 340 435 164 110 158 230 408 106 470 500 162 361 263 101 143 303 259 83 478 264 432 331 202 84 222 322 229 348 474 286 269 499 176 482 151 80 284 486 490 292 210 182 300 233 366 288 359 261 388 390 418 64 173 49 198 26 374 326 391 215 328 282 207 157 12 262 153 327 120 72 214 416 368 407 250 440 255 14 459 460 405 290 130 298 273 451 404 411 315 477 121 289 179 484 465 421 191 309 73 413 386 150 89 396 133 375 181 427 275 335 429 22 44 203 320 277 97 337 349 119 305 213 9 68 144 212 11 406 125 488 88 200 314 293 74 354 272 281 425 190 175 201 419 209 389 99 414 306 199 433 483 245 56 188 220 285 36 21 347 69 295 400 187 105 395 193 423 71 464 371 219 417 412 476 401 296 403 107 211 217 367 397 313 149 274 33 301 31 270 333 445 178 159 442 438 415 252 312 287 172 363 352 318 42 174 258 280 63 321 115 475 19 165 493 455 283 260 224 480 237 61 394 343 304 139 428 141 167 196 453 239 154 247 166 65 205 410 457 242 58 345 332 344 307 481 248 122 17 111 253 231 310 227 25 46 271 76 393 402 78 109 372 95 266 324 350 311 329 244 323 330 409 450 379 57 251 142 243 461 7 240 197 491 492 53 116 96 439 170 43 86 387 54 206 156 59 169 180 469 62 131 424 90 51 127 87 3 129 376 168 279 378 370 161 226 373 249 369 34 356 485 265 443 177 498 463 6 302 18 132 41 24 79 353 81 98 160 204 29 380 364 334 444 66 381 325 487 32 448 431 136 138 278 392 118 462 236 10 100 92 52 319 472 232 234 195 171 223 37 399 85 383 60 268 82 28 30 420 77 117 189 294 147 256 155 291 35 238 235 365 8 38 308 316 384 246 40 134 339 123 184 15 4 148 342 112 192 104 114 50 208 5 267 55 93 299 39 496 467 228 128 135 241 163 360 67 47 434 449 113 494 430 446 23 358 385 441 221 1 126 48 140 317 152 497 137 357 471 218 91 27 146 13 426 468 20 422 351 2 456 194 341 355 225 257 254 185 437 16 "; ./push_swap $ARG | ./checker_linux $ARG

// ARG="14 468 259 21 269 190 137 360 352 46 81 296 432 155 80 117 70 312 63 158 171 3 217 31 344 283 462 389 386 203 465 153 279 157 369 19 365 52 195 133 476 28 64 273 444 387 202 129 469 8 308 233 336 42 314 246 380 184 44 480 106 459 290 474 97 74 463 192 94 173 405 207 277 13 239 350 485 400 40 200 276 433 67 288 429 305 309 89 338 337 83 175 71 364 431 88 393 103 275 258 72 33 482 26 302 375 151 260 355 243 420 125 24 6 149 430 238 60 252 69 15 477 499 162 237 285 240 143 9 216 235 181 500 251 34 174 96 407 135 449 241 16 351 92 10 496 53 7 353 230 428 93 362 177 417 481 123 144 204 61 421 317 111 404 390 331 325 170 54 494 43 219 55 223 470 77 256 339 450 441 118 167 410 234 422 372 289 32 464 455 379 41 419 20 145 250 447 224 492 497 169 124 346 373 136 119 437 434 165 73 261 330 311 452 287 147 85 91 328 194 304 442 402 2 438 466 458 298 427 460 396 448 140 439 107 222 139 113 132 108 264 461 423 486 130 445 366 284 30 493 303 357 274 399 104 141 11 27 272 193 443 112 367 382 472 425 301 268 65 22 160 210 326 270 368 267 255 488 188 68 394 48 313 38 213 414 473 244 424 254 99 310 418 120 321 245 320 413 47 263 281 286 342 498 101 134 371 456 90 242 51 426 166 322 398 208 215 82 109 412 315 334 278 114 292 75 152 335 196 483 221 395 191 299 180 291 370 329 401 1 17 176 23 257 297 293 209 307 377 146 280 319 408 179 121 100 37 168 35 249 189 49 110 266 156 172 253 229 95 62 333 198 4 76 36 87 392 178 59 186 347 78 318 236 231 403 323 361 18 164 206 183 489 205 185 199 128 220 475 150 411 232 341 384 340 218 495 131 391 479 159 86 471 248 435 381 332 163 359 12 282 397 376 50 225 295 327 300 142 454 446 45 416 306 228 154 122 247 214 161 348 187 487 467 182 271 201 127 374 453 388 265 84 484 354 406 212 211 226 415 436 148 440 343 349 478 490 25 324 383 138 409 378 345 5 58 451 29 56 356 115 39 197 294 457 126 316 116 227 262 358 79 385 363 57 491 105 66 98 102 "; ./push_swap $ARG | ./checker_linux $ARG
